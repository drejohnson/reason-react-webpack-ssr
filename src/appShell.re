[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

type renderElement = ReasonReact.reactElement => ReasonReact.reactElement;

let rootId = Utils.getElementById(Utils.dom, "root");

let onLocationChange = (location, router) => {
  let currentLocation = location;
  if (currentLocation##key !== location##key) {
    ()
  };
  router
  |> UniversalRouter.resolve({"pathname": location##pathname})
  |> Js.Promise.then_(
       (component: ReasonReact.reactElement) => {
         Js.log("Rendering route : " ++ location##pathname);
         hydrate(<App> component </App>, rootId);
         Js.Promise.resolve()
       }
     )
};

let bootstrap = (history) => {
  let dispatcher = (target, event) => {
    Js.log("Redirect to " ++ target);
    ReactEventRe.Mouse.preventDefault(event);
    history##push(target)
  };
  let router = UniversalRouter.clientRouter(Routes.handlers(dispatcher));
  history##listen((location) => onLocationChange(location, router));
  router
};