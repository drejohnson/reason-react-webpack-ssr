type t;

type connection;

type db;

type request;

type parent;

type ctx;

type info;

type result;

type resolvers = {
  .
  "Query": {
    .
    "hello": (parent, {. "name": string}, ctx, info) => Js.Promise.t(string),
  },
};
