let component = ReasonReact.statelessComponent("App");

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement("div", ~props={"style": Js.Nullable.from_opt(style)}, children)
};