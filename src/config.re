[@bs.module "dotenv"] external config : {. "silent": bool} => unit = "";

config({"silent": true});

let getEnvVar = (key, fallback) =>
  Js.Option.getWithDefault(
    fallback,
    Js.Dict.get(Node.Process.process##env, key),
  );

module Env = {
  let isDev = getEnvVar("NODE_ENV", "production") === "development";
  let port = Utils.parseInt(getEnvVar("PORT", "8080"), 10);
};

module App = {
  let title = "ReasonReact Starter Kit";
  let description = "Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems.";
};