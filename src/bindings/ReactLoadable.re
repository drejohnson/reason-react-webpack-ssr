type loadOptions = {. "loader": unit => string, "loading": ReasonReact.reactClass};

[@bs.module] external load : loadOptions => ReasonReact.reactClass = "react-loadable";