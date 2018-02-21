let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) => <Fragment> <Async.Hello message="Hello from home component" /> </Fragment>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));