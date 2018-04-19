let component = ReasonReact.statelessComponent("App");

let make = (~initialUrl=?, _children) => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title> (Config.App.title |> Utils.text) </title>
        /* Search Engine */
        <meta name="description" content=Config.App.description />
        <meta name="image" content="https://example.com/images/image.png" />
        /* Twitter */
        <meta name="twitter:card" content="summary" />
        <meta name="twitter:title" content=Config.App.title />
        <meta name="twitter:description" content=Config.App.description />
        <meta name="twitter:site" content="@twitterHandle" />
        <meta name="twitter:creator" content="@twitterHandle" />
        <meta
          name="twitter:image:src"
          content="https://example.com/images/image.png"
        />
        /* Open Graph general (Facebook, Pinterest & Google+) */
        <meta name="og:title" content=Config.App.title />
        <meta name="og:description" content=Config.App.description />
        <meta
          name="og:image"
          content="https://example.com/images/preview.png"
        />
        <meta name="og:url" content="https://example.com" />
        <meta name="og:site_name" content=Config.App.title />
        <meta name="og:locale" content="en_US" />
        <meta name="og:type" content="website" />
        /* PWA Specific */
        <meta name="theme-color" content="#000000" />
        <link rel="manifest" href="/manifest.json" />
        <link rel="shortcut icon" href="/favicon.ico" />
      </ReactHelmet>
      <Layout>
        <Router.Container initialUrl>
          ...(
               (~initialUrl) =>
                 switch (initialUrl) {
                 | Home => <Home />
                 | About => <About />
                 | _ => <NotFound />
                 }
             )
        </Router.Container>
      </Layout>
    </Fragment>,
};