[@bs.val] external app_bundle : string = "APP_BUNDLE";

[@bs.val] external vendor_bundle : string = "VENDOR_BUNDLE";

module Status = {
  let make = () =>
    Express.PromiseMiddleware.from(
      (_next, _req, res) => Express.Response.sendString("works", res) |> Js.Promise.resolve
    );
};

module RenderApp = {
  let make = () =>
    Express.PromiseMiddleware.from(
      (_next, req, res) => {
        let helmetContext = Js.Obj.empty();
        let path = req |> Express.Request.path;
        let app =
          <ReactHelmet.Provider context=helmetContext>
            <App initialUrl=path />
          </ReactHelmet.Provider>;
        LoadableComponents.getLoadableState(app)
        |> Js.Promise.then_(
             (loadableState) =>
               ReactApollo.getDataFromTree(app)
               |> Js.Promise.then_(
                    () =>
                      {
                        let title = helmetContext##helmet##title##toString();
                        let meta = helmetContext##helmet##meta##toString();
                        let link = helmetContext##helmet##link##toString();
                        let script = helmetContext##helmet##script##toString();
                        let htmlAttr = helmetContext##helmet##htmlAttributes##toString();
                        let loadableScript = loadableState |> LoadableComponents.getScriptTag;
                        let content = ReactDOMServerRe.renderToString(app);
                        Express.Response.sendString(
                          Template.make(
                            ~content,
                            ~title,
                            ~meta,
                            ~link,
                            ~script,
                            ~htmlAttr,
                            ~app_bundle,
                            ~vendor_bundle,
                            ~loadableScript,
                            ()
                          ),
                          res
                        )
                      }
                      |> Js.Promise.resolve
                  )
           )
      }
    );
};

module Webpack = {
  type compiler;
  [@bs.module] external webpack : Js.Json.t => compiler = "webpack";
  [@bs.module]
  external devMiddleware :
    (compiler, {. "logLevel": string, "serverSideRender": bool, "stats": string}) => 'a =
    "webpack-dev-middleware";
  [@bs.module] external hotMiddleware : compiler => 'a = "webpack-hot-middleware";
  [@bs.module] external config : Js.Json.t = "../../../../webpack.config";
  let config = config;
  let compiler = webpack(config);
  let webpackDevMiddleware =
    devMiddleware(compiler, {"logLevel": "error", "serverSideRender": true, "stats": "minimal"});
  let webpackHotMiddleware = hotMiddleware(compiler);
};