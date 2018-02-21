[@bs.module "dotenv"] external config : {. "silent": bool} => unit = "config";

/* Load environment variables from a .env file if it exists */
config({"silent": true});

let getEnvVar = (key, fallback) =>
  Js.Option.getWithDefault(fallback, Js.Dict.get(Node.Process.process##env, key));

module Server = {
  let port = Utils.parseInt(getEnvVar("PORT", "8080"), 10);
  let isDev = getEnvVar("NODE_ENV", "development") === "development";
};