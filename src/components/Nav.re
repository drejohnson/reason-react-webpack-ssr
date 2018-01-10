let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  ...component,
  render: (_self) => <nav> ("Nav goes here" |> Utils.text) </nav>
};