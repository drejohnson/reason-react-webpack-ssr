[@bs.module "react-apollo"] external renderToStringWithData : string => Js.Promise.t('a) =
  "renderToStringWithData";

[@bs.module "react-apollo"] external getDataFromTree : string => Js.Promise.t('a) =
  "getDataFromTree";

module ApolloProvider = {
  [@bs.module "react-apollo"] external reactClass : ReasonReact.reactClass = "ApolloProvider";
  let make = (~client: ApolloClient.generatedApolloClient, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"client": client}, children);
};