let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> (Config.App.title |> Utils.text) </title>
        <meta name="description" content=Config.App.description />
      </ReactHelmet>
      <section>
        <ContentHeader section="ReasonReact" title="Fullstack GraphQL" />
        <LazyHello render=(((module Hello)) => <Hello name="John Snow" />) />
      </section>
    </Fragment>,
};