open Express.App;

[@bs.module] external morgan : string => Express.Middleware.t = "";

[@bs.module] external helmet : unit => Express.Middleware.t = "";

let onListen = (exn) => {
  let error = Js.Nullable.to_opt(exn);
  switch error {
  | Some(err) =>
    Js.log(
      Chalk.red("Express listen error: ")
      ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err))
    )
  | None =>
    Js.log(
      Chalk.blue("Express server")
      ++ " is listening on port "
      ++ Chalk.green(Js.Int.toString(Config.Server.port))
    )
  }
};

let start = () => {
  let app = Express.App.make();
  Config.Server.isDev ? use(app, morgan("dev")) : use(app, morgan("combined"));
  use(app, helmet());
  if (Config.Server.isDev) {
    use(app, Webpack.webpackDevMiddleware);
    use(app, Webpack.webpackHotMiddleware)
  };
  useOnPath(
    app,
    ~path="/",
    Express.Static.make("dist/client", Express.Static.defaultOptions())
    |> Express.Static.asMiddleware
  );
  useOnPath(
    app,
    ~path="/",
    Express.Static.make("public", Express.Static.defaultOptions()) |> Express.Static.asMiddleware
  );
  get(app, ~path="*", Middleware.App.make());
  listen(app, ~port=Config.Server.port, ~onListen, ())
};

start();