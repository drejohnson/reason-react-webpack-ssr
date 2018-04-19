[%bs.raw "require('isomorphic-unfetch')"];

/* open ApolloLinks; */
open ApolloInMemoryCache;

type dataObject = {
  .
  "__typename": string,
  "id": string,
};

[@bs.send] external clientCache : 'a => Js.Json.t = "cache";

[@bs.send.pipe: 't] external extract : unit => Js.Json.t = "extract";

/* Create an InMemoryCache */
let inMemoryCache =
  createInMemoryCache(~dataIdFromObject=(obj: dataObject) => obj##id, ());

/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri="http://localhost:4000/", ());

let client =
  ReasonApollo.createApolloClient({
    "link": httpLink,
    "cache":
      Utils.isNode ?
        inMemoryCache : inMemoryCache |> restore(Utils.apollo_state),
    "ssrMode": Js.Nullable.return(! Utils.isBrowser),
    "ssrForceFetchDelay":
      Utils.isBrowser ? Js.Nullable.return(100) : Js.Nullable.undefined,
    "connectToDevTools": Js.Nullable.undefined,
    "queryDeduplication": Js.Nullable.undefined,
  });