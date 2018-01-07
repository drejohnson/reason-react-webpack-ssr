[%bs.raw "require('isomorphic-unfetch')"];

type dataObject = {. "__typename": string, "id": string, "key": string};

type inMemoryCacheConfig = {. "dataIdFromObject": dataObject => string};

type restoreData;

type apolloLink;

[@bs.obj]
external clientOptions :
  (
    ~ssrMode: Js.boolean=?,
    ~ssrForceFetchDelay: int=?,
    ~link: apolloLink=?,
    ~cache: unit=?,
    unit
  ) =>
  'a =
  "";

[@bs.module "apollo-client"] [@bs.new]
external apolloClient : 'clientOptions => ApolloClient.generatedApolloClient =
  "ApolloClient";

[@bs.module "apollo-cache-inmemory"] [@bs.new]
external inMemoryCache : option(inMemoryCacheConfig) => 'a =
  "InMemoryCache";

[@bs.module "apollo-link-http"] [@bs.new]
external httpLink : ApolloClient.linkOptions => apolloLink =
  "HttpLink";

[@bs.module "apollo-link-http"] external createHttpLink : ApolloClient.linkOptions => apolloLink =
  "";

[@bs.send.pipe : 't] external restore : 'a => unit = "restore";

[@bs.scope "cache"] [@bs.send.pipe : 't] external extract : unit => Js.Json.t = "extract";

module type CreationConfig = {let initApolloClient: ApolloClient.generatedApolloClient;};

module Create = (CreationConfig: CreationConfig) => {
  let apolloClient = CreationConfig.initApolloClient;
  module Query =
    ReasonApolloQuery.QueryFactory(
      {
        let apolloClient = apolloClient;
      }
    );
  module Mutation =
    ReasonApolloMutation.MutationFactory(
      {
        let apolloClient = apolloClient;
      }
    );
  module InitApolloClient = {};
};