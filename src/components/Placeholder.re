let component = ReasonReact.statelessComponent("Placeholder");

let make = _children => {
  ...component,
  render: _self => <h1> ("Loading ..." |> Utils.text) </h1>,
};