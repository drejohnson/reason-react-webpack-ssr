[@bs.module "react-apollo"]
external getDataFromTree : ReasonReact.reactElement => Js.Promise.t(unit) =
  "getDataFromTree";

[@bs.module] external assets : Js.Json.t = "./asset-manifest.json";

[@bs.module] external chunks_ : Js.Json.t = "./chunk-manifest.json";

module Decode = {
  type chunk = string;
  let chunks = json : array(chunk) =>
    Json.Decode.(json |> field("client", array(string)));
};

let app = Express.App.make();

let renderHTML = (_next, req, res) => {
  let path = req |> Express.Request.path;
  let app =
    <ReasonApollo.Provider client=Apollo.client>
      <App initialUrl=path />
    </ReasonApollo.Provider>;
  getDataFromTree(app)
  |> Js.Promise.then_(() =>
       {
         let helmet = ReactHelmet.renderStatic();
         let title = helmet##title##toString();
         let meta = helmet##meta##toString();
         let link = helmet##link##toString();
         let script = helmet##script##toString();
         let htmlAttr = helmet##htmlAttributes##toString();
         let chunks = chunks_ |> Decode.chunks;
         let initialState = Apollo.client |> Apollo.extract();
         let content = ReactDOMServerRe.renderToString(app);
         Express.Response.sendString(
           Template.make(
             ~content,
             ~title,
             ~meta,
             ~link,
             ~script,
             ~htmlAttr,
             ~state=initialState,
             ~chunks,
             (),
           ),
           res,
         );
       }
       |> Js.Promise.resolve
     );
};

Express.Static.defaultOptions()
|> Express.Static.make("public")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/");

Express.Static.defaultOptions()
|> Express.Static.make("build/public")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/");

renderHTML
|> Express.PromiseMiddleware.from
|> Express.App.get(app, ~path="*");

let onListen = exn => {
  let error = Js.Nullable.toOption(exn);
  switch (error) {
  | Some(err) =>
    Js.log(
      "Express listen error: "
      ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err)),
    )
  | None =>
    Js.log(" ...listening on port " ++ Js.Int.toString(Config.Env.port))
  };
};

if (! Utils.moduleHot) {
  Express.App.listen(app, ~port=Config.Env.port, ~onListen, ());
};

if (Utils.moduleHot) {
  %raw
  {|app.hot = module.hot|};
  Utils.moduleHot |> Utils.accept;
};