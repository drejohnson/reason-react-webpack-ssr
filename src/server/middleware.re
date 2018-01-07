type asyncMiddleware =
  (Express.Request.t, Express.Response.t, Express.Next.t) => Js.Promise.t(Express.done_);

external asyncMiddlewareFrom : asyncMiddleware => Express.Middleware.t = "%identity";

[@bs.val] external app_bundle : string = "APP_BUNDLE";

[@bs.val] external vendor_bundle : string = "VENDOR_BUNDLE";

module Status = {
  let make = () =>
    asyncMiddlewareFrom(
      (_req, res, _next) => Express.Response.sendString(res, "works") |> Js.Promise.resolve
    );
};

module App = {
  let make = () =>
    asyncMiddlewareFrom(
      (req, res, _next) => {
        let dispatcher = (target, event) => {
          let history = History.createBrowserHistory();
          ReactEventRe.Mouse.preventDefault(event);
          history##push(target)
        };
        let universalRouter = UniversalRouter.serverRouter(Routes.handlers(dispatcher));
        universalRouter
        |> UniversalRouter.resolve({"pathname": Express.Request.path(req)})
        |> Js.Promise.then_(
             (component) => {
               let html =
                 ReactDOMServerRe.renderToString(
                   <App> component </App>
                 );
               ReactApollo.getDataFromTree(html)
               |> Js.Promise.then_(
                    () => {
                      let helmet = ReactHelmet.renderStatic();
                      let helmetHtmlAttributes = helmet##htmlAttributes##toString();
                      let helmetTitle = helmet##title##toString();
                      let helmetMeta = helmet##meta##toString();
                      let helmetLink = helmet##link##toString();
                      let helmetScript = helmet##script##toString();
                      let state = Apollo.initialState;
                      Express.Response.sendString(
                        res,
                        Render.view(
                          html,
                          state,
                          helmetHtmlAttributes,
                          helmetTitle,
                          helmetMeta,
                          helmetLink,
                          helmetScript,
                          app_bundle,
                          vendor_bundle
                        )
                      )
                      |> Js.Promise.resolve
                    }
                  )
             }
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