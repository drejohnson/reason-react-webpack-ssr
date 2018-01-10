/* Hashed assets not working for ssr */
let logo =
  Utils.isPROD ? "/images/logo.svg" : Utils.requireAssetURI("../../static/images/logo.svg");

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header> <img src="/images/logo.svg" alt="logo" width="200px" /> <Nav /> </header>
};