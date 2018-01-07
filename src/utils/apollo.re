[%bs.raw "require('isomorphic-unfetch')"];

type window;

[@bs.set] external set_apollo_state : (window, string) => unit = "__APOLLO_STATE__";

let httpLinkOptions: ApolloClient.linkOptions = {
  "uri": "https://api.graph.cool/simple/v1/PHRESHR"
};

let apolloClientOptions =
  ApolloClientCustom.clientOptions(
    ~ssrMode=Js.Boolean.to_js_boolean(Utils.isBrowser),
    ~cache=ApolloClientCustom.inMemoryCache(None),
    ~link=ApolloClient.httpLink(httpLinkOptions),
    ()
  );

let client = ApolloClient.apolloClient(apolloClientOptions);

let initialState = client |> ApolloClientCustom.extract();

module Client =
  ApolloClientCustom.Create(
    {
      let initApolloClient = ApolloClient.apolloClient(apolloClientOptions);
    }
  );