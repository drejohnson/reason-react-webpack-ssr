module Config = {
  module type t = (module type of Hello);
};

module Loadable = ReLoadable.WithRender(Config);

let make = _children =>
  Loadable.make(~fetch=() => DynamicImport.import("./Hello.bs.js"), [||]);