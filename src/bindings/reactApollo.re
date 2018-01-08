[@bs.module "react-apollo"] external renderToStringWithData : string => Js.Promise.t('a) =
  "renderToStringWithData";

[@bs.module "react-apollo"] external getDataFromTree : string => Js.Promise.t('a) =
  "getDataFromTree";