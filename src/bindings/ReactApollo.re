[@bs.module "react-apollo"]
external getDataFromTree : ReasonReact.reactElement => Js.Promise.t(unit) =
  "getDataFromTree";

module ApolloProvider = {
  [@bs.module "react-apollo"] external apollo_provider : ReasonReact.reactClass = "ApolloProvider";
  let make = (~client: option(Js.Json.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=apollo_provider,
      ~props={"client": Js.Nullable.from_opt(client)},
      children
    );
};