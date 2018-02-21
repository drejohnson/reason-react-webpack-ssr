type getComponent = unit => string;

type error;

type loadableState;

type loadableOptions = {
  .
  /* "ErrorComponent": error => ReasonReact.reactClass,
     "LoadingComponent": unit => ReasonReact.reactClass,
     "render": unit, */
  "modules": array(string)
};

[@bs.module "loadable-components"] external loadComponents : unit => Js.Promise.t('a) = "";

[@bs.module "loadable-components"]
external loadable : (getComponent, loadableOptions) => ReasonReact.reactClass =
  "default";

[@bs.module "loadable-components/server"]
external getLoadableState :
  ReasonReact.reactElement => Js.Promise.t((loadableState => loadableState)) =
  "";

[@bs.send.pipe : 't] external getScriptTag : Js.Promise.t(unit) = "";

[@bs.send.pipe : 't] external getScriptElement : Js.Promise.t(unit) = "";