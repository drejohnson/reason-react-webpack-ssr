[@bs.val] external window : Dom.window = "window";

[@bs.scope "window"] [@bs.val] external window_location : string = "location";

[@bs.scope ("window", "location")] [@bs.val] external window_location_pathname : string =
  "pathname";

[@bs.val] [@bs.return nullable] external _getElementById : string => option(Dom.element) =
  "document.getElementById";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

[@bs.val] external parseInt : (string, int) => int = "";

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

let parseInt_ = (int, string) => parseInt(string, int);

let isPROD = nodeEnv === "production";

let isDEV = nodeEnv !== "production";

let isBrowser = Js.typeof(window: Dom.window) !== "undefined";

let isNode = Js.typeof(window: Dom.window) === "undefined";

module Text = {
  let string = ReasonReact.stringToElement;
  let int = (n) => n |> string_of_int |> string;
  let float = (f) => f |> string_of_float |> string;
  let any = (v) => v |> Js.String.make |> string;
};

let text = Text.string;

let list = (list) => list |> Array.of_list |> ReasonReact.arrayToElement;

let array = (array) => array |> ReasonReact.arrayToElement;

/**
  * Safely converts an object to json by stringifying it and parsing the results.
  */
let objToJson = (obj: Js.t('a)) : Js.Json.t => {
  let str = Js.Json.stringifyAny(obj);
  /* parseExn should be safe because the string came from stringifyAny */
  switch str {
  | Some(str) => str |> Js.Json.parseExn
  | None => Js.Json.null
  }
};