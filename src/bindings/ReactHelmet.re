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

[@bs.module "react-helmet"] external helmet : ReasonReact.reactClass = "Helmet";

[@bs.val] [@bs.scope "Helmet"] [@bs.module "react-helmet"]
external renderStatic : unit => Js.t('a) =
  "renderStatic";

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
      ~onChangeClientState: option(((~newState: t) => t))=?,
      ~script: option(array(script))=?,
      ~style: option(array(style))=?,
      ~title: option(string)=?,
      ~titleAttributes: option(titleAttributes)=?,
      ~titleTemplate: option(string)=?,
      children
    ) => {
  let props = {
    "base": Js.Nullable.from_opt(base),
    "bodyAttributes": Js.Nullable.from_opt(bodyAttributes),
    "defaultTitle": Js.Nullable.from_opt(defaultTitle),
    "encodeSpecialCharacters": Js.Boolean.to_js_boolean(encodeSpecialCharacters),
    "htmlAttributes": Js.Nullable.from_opt(htmlAttributes),
    "link": Js.Nullable.from_opt(link),
    "meta": Js.Nullable.from_opt(meta),
    "noscript": Js.Nullable.from_opt(noscript),
    "onChangeClientState": Js.Nullable.from_opt(onChangeClientState),
    "script": Js.Nullable.from_opt(script),
    "style": Js.Nullable.from_opt(style),
    "title": Js.Nullable.from_opt(title),
    "titleAttributes": Js.Nullable.from_opt(titleAttributes),
    "titleTemplate": Js.Nullable.from_opt(titleTemplate)
  };
  ReasonReact.wrapJsForReason(~reactClass=helmet, ~props, children)
};