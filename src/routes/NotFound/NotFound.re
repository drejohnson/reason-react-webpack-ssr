let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("404 - Page Not Found" |> Utils.text) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section>
        <ContentHeader section="ReasonReact" title="Fullstack Example" />
        <LazyHello render=(((module Hello)) => <Hello name="404 Page" />) />
      </section>
    </Fragment>,
};