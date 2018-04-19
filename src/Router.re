module RouterConfig = {
  type route =
    | Home
    | About
    | NotFound;
  let urlToRoute: ReasonReact.Router.url => route =
    url =>
      switch (url.path) {
      | [] => Home
      | ["about"] => About
      | _ => NotFound
      };
};

module Container = {
  type state = ReasonReact.Router.url;
  type action =
    | UpdateRoute(ReasonReact.Router.url);
  let component = ReasonReact.reducerComponent("Router");
  let make:
    (~initialUrl: option(string), 'a) =>
    ReasonReact.component(state, _, action) =
    (~initialUrl, children) => {
      ...component,
      initialState: () =>
        switch (initialUrl) {
        | Some(url) => {path: Utils.parseUrlPath(url), hash: "", search: ""}
        | None => ReasonReact.Router.dangerouslyGetInitialUrl()
        },
      reducer: (action, _state) =>
        switch (action) {
        | UpdateRoute(url) => ReasonReact.Update(url)
        },
      subscriptions: ({send}) => [
        Sub(
          () => ReasonReact.Router.watchUrl(url => send(UpdateRoute(url))),
          ReasonReact.Router.unwatchUrl,
        ),
      ],
      render: ({state}) =>
        children(~initialUrl=state |> RouterConfig.urlToRoute),
    };
};