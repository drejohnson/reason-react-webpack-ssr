let component = ReasonReact.statelessComponent("Layout");

let make =
    (
      ~html,
      ~state,
      ~helmetHtmlAttributes,
      ~helmetTitle,
      ~helmetMeta,
      ~helmetLink,
      ~helmetScript,
      ~app_bundle,
      ~vendor_bundle,
      _children
    ) => {
  ...component,
  render: (_self) =>
    <html lang="en">
      <head> helmetMeta helmetTitle helmetLink helmetScript </head>
      <body>

          <div id="root" dangerouslySetInnerHTML={"__html": html} />
          <script src=vendor_bundle />
          <script src=app_bundle />
        </body>
        /* <script dangerouslySetInnerHTML={"__html": Js.Json.stringify(state)} /> */
    </html>
};