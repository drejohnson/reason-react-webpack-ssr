type t;

[@bs.obj]
external route :
  (
    ~path: string,
    ~name: string=?,
    ~children: array(Js.t({..}))=?,
    ~action: unit => 'component=?,
    unit
  ) =>
  t =
  "";

[@bs.module] [@bs.new] external serverRouter : array('routes) => t = "universal-router";

[@bs.module "universal-router"] [@bs.new] external clientRouter : array('routes) => t = "default";

[@bs.send.pipe : 't] external resolve : Js.t({..}) => 'component = "resolve";