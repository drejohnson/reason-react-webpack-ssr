[@bs.val] external window : Dom.window = "window";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.val] external parseInt : (string, int) => int = "";

[@bs.val] external moduleHot : 'a = "module.hot";

[@bs.send.pipe: 't] external accept : unit = "";

[@bs.scope "window"] [@bs.val] external apollo_state : 'a = "__APOLLO_STATE__";

[@bs.set]
external set_apollo_state : (Dom.window, string) => unit = "__APOLLO_STATE__";

let parseInt_ = (int, string) => parseInt(string, int);

let isBrowser = Js.typeof(window: Dom.window) !== "undefined";

let isNode = Js.typeof(window: Dom.window) === "undefined";

/* Copied from Vrroom */
module Text = {
  let string = ReasonReact.stringToElement;
  let int = n => n |> string_of_int |> string;
  let float = f => f |> string_of_float |> string;
  let any = v => v |> Js.String.make |> string;
};

let text = Text.string;

/* Array to List helper */
let list = list => list |> Array.of_list |> ReasonReact.arrayToElement;

/* Array to Element helper */
let array = array => array |> ReasonReact.arrayToElement;

let parseUrlPath = url =>
  switch (url) {
  | ""
  | "/" => []
  | _ =>
    /* remove the preceeding /, which every pathname seems to have */
    let raw = Js.String.sliceToEnd(~from=1, url);
    /* remove the trailing /, which some pathnames might have. Ugh */
    let raw =
      switch (Js.String.get(raw, Js.String.length(raw) - 1)) {
      | "/" => Js.String.slice(~from=0, ~to_=-1, raw)
      | _ => raw
      };
    raw |> Js.String.split("/") |> Array.to_list;
  };