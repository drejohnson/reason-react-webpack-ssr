open Types;

let hello: (parent, {. "name": string}, ctx, info) => Js.Promise.t(string) =
  (parent, n, ctx, info) => {
    let name = n##name;
    let value = {j|Hello $name|j};
    value |> Js.Promise.resolve;
  };
