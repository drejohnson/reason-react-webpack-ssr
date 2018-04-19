type t;

type base;

type bodyAttributes;

type htmlAttributes;

type link;

type meta;

type noscript;

type script;

type style;

type titleAttributes;

[@bs.module "react-helmet"]
external helmet : ReasonReact.reactClass = "Helmet";

[@bs.val] [@bs.scope "Helmet"] [@bs.module "react-helmet"]
external renderStatic : unit => Js.t('a) = "renderStatic";

let make =
    (
      ~base: option(base)=?,
      ~bodyAttributes: option(bodyAttributes)=?,
      ~defaultTitle: option(string)=?,
      ~encodeSpecialCharacters: bool=false,
      ~htmlAttributes: option(htmlAttributes)=?,
      ~link: option(array(link))=?,
      ~meta: option(array(meta))=?,
      ~noscript: option(array(noscript))=?,
      ~onChangeClientState: option((~newState: t) => t)=?,
      ~script: option(array(script))=?,
      ~style: option(array(style))=?,
      ~title: option(string)=?,
      ~titleAttributes: option(titleAttributes)=?,
      ~titleTemplate: option(string)=?,
      children,
    ) => {
  let props = {
    "base": Js.Nullable.fromOption(base),
    "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
    "defaultTitle": Js.Nullable.fromOption(defaultTitle),
    "encodeSpecialCharacters": encodeSpecialCharacters,
    "htmlAttributes": Js.Nullable.fromOption(htmlAttributes),
    "link": Js.Nullable.fromOption(link),
    "meta": Js.Nullable.fromOption(meta),
    "noscript": Js.Nullable.fromOption(noscript),
    "onChangeClientState": Js.Nullable.fromOption(onChangeClientState),
    "script": Js.Nullable.fromOption(script),
    "style": Js.Nullable.fromOption(style),
    "title": Js.Nullable.fromOption(title),
    "titleAttributes": Js.Nullable.fromOption(titleAttributes),
    "titleTemplate": Js.Nullable.fromOption(titleTemplate),
  };
  ReasonReact.wrapJsForReason(~reactClass=helmet, ~props, children);
};