let component = ReasonReact.statelessComponent("Layout");

let make = children => {
  ...component,
  render: _self => <Fragment> <Header /> children[0] </Fragment>,
};