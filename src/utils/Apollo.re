[%bs.raw "require('isomorphic-unfetch')"];

module InMemoryCache =
  ApolloInMemoryCache.CreateInMemoryCache(
    {
      type dataObject;
      let inMemoryCacheObject = Js.Nullable.undefined;
    }
  );

/* Create an HTTP Link */
module HttpLink =
  ApolloHttpLink.CreateHttpLink(
    {
      let uri = "https://api.graph.cool/simple/v1/PHRESHR";
    }
  );

let apolloClientOptions =
  ApolloClient.clientOptions(
    ~ssrMode=Js.Boolean.to_js_boolean(true),
    ~cache=InMemoryCache.cache,
    ~link=HttpLink.link,
    ()
  );

module Client =
  ReasonApollo.Create(
    {
      let createApolloClient = ApolloClient.apolloClient(apolloClientOptions);
    }
  );

let apolloClient = Client.apolloClient;