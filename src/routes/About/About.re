let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("ReasonReact Fullstack" |> Utils.text) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section>
        <ContentHeader section="ReasonReact" title="Fullstack Example" />
        <LazyHello
          render=(((module Hello)) => <Hello name="Pedro for President" />)
        />
      </section>
    </Fragment>,
};