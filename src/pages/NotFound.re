let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) => <Hello message="Page not found" />
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));