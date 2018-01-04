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
               let html = ReactDOMServerRe.renderToString(<App> component </App>);
               let helmet = ReactHelmet.renderStatic();
               let helmetHtmlAttributes = helmet##htmlAttributes##toString();
               let helmetTitle = helmet##title##toString();
               let helmetMeta = helmet##meta##toString();
               let helmetLink = helmet##link##toString();
               let helmetScript = helmet##script##toString();
               let render = () =>
                 Express.Response.sendString(
                   res,
                   Render.view(
                     html,
                     helmetHtmlAttributes,
                     helmetTitle,
                     helmetMeta,
                     helmetLink,
                     helmetScript,
                     app_bundle,
                     vendor_bundle
                   )
                 );
               render() |> Js.Promise.resolve
             }
           )
      }
    );
};