open Middleware;

let app = Express.App.make();

if (Config.Server.isDev) {
  Webpack.webpackDevMiddleware |> Express.App.use(app);
  Webpack.webpackHotMiddleware |> Express.App.use(app)
};

Express.Static.defaultOptions()
|> Express.Static.make("dist/static")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/static");

Express.App.get(app, ~path="/*", RenderApp.make());

let onListen = (exn) => {
  let error = Js.Nullable.to_opt(exn);
  switch error {
  | Some(err) =>
    Js.log(
      "Express listen error: " ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err))
    )
  | None => Js.log(" ...listening on port " ++ Js.Int.toString(Config.Server.port))
  }
};

Express.App.listen(app, ~port=Config.Server.port, ~onListen, ());