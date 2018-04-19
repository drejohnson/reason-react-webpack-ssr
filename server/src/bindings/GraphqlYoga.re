open Types;

type schema;

type contextParameters = {
  request: Express.Request.t,
  connection,
};

type contextObj = {
  .
  "db": db,
  "req": contextParameters,
};

type contextCallback = contextParameters => contextObj;

type context = [@bs.unwrap] [ | `Obj(contextObj) | `Fn(contextCallback)];

type serverProps = {
  .
  "typeDefs": Js.Nullable.t(string),
  "resolvers": Js.Nullable.t(resolvers),
  "schema": Js.Nullable.t(schema),
  "context": Js.Nullable.t(contextCallback),
};

[@bs.module "graphql-yoga"] [@bs.new]
external makeGraphQLServer : serverProps => 'a = "GraphQLServer";

[@bs.send.pipe: 'a] external start : 'a => 'a = "";

let createGraphQLServer =
    (~typeDefs=?, ~resolvers=?, ~schema=?, ~context=?, ()) => {
  let graphQLServerOptions = {
    "typeDefs": Js.Nullable.fromOption(typeDefs),
    "resolvers": Js.Nullable.fromOption(resolvers),
    "schema": Js.Nullable.fromOption(schema),
    "context": Js.Nullable.fromOption(context),
  };
  makeGraphQLServer(graphQLServerOptions);
};
