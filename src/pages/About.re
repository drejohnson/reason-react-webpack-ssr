let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) => <Hello message="Hello from about component" />
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));