module Config = {
  module type t = (module type of NotFound);
};

include ReLoadable.WithRender(Config);