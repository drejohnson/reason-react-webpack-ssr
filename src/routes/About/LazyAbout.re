module Config = {
  module type t = (module type of About);
};

include ReLoadable.WithRender(Config);