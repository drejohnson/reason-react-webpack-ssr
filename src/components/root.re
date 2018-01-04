let component = ReasonReact.statelessComponent("Root");

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement("div", ~props={"style": Js.Nullable.from_opt(style)}, children)
};