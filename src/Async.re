module Home = {
  let reactClass =
    LoadableComponents.loadable(
      () => [%bs.raw {|import("./pages/Home.bs") |}],
      {"modules": [|"./pages/Home.bs"|]}
    );
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module About = {
  let reactClass =
    LoadableComponents.loadable(
      () => [%bs.raw {|import("./pages/About.bs") |}],
      {"modules": [|"./pages/About.bs"|]}
    );
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module NotFound = {
  let reactClass =
    LoadableComponents.loadable(
      () => [%bs.raw {|import("./pages/NotFound.bs") |}],
      {"modules": [|"./pages/NotFound.bs"|]}
    );
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Hello = {
  let reactClass =
    LoadableComponents.loadable(
      () => [%bs.raw {|import("./components/Hello.bs") |}],
      {"modules": [|"./components/Hello.bs"|]}
    );
  let make = (~message, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"message": message}, children);
};