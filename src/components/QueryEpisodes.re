module FetchEpisodes = Apollo.Client.Query(QueryEpisodesConfig);

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <FetchEpisodes>
      (
        (response) =>
          switch response {
          | Loading => <div> (Utils.text("Loading")) </div>
          | Failed(error) => <div> (Utils.text(error)) </div>
          | Loaded(result) =>
            <div>
              (
                ReasonReact.arrayToElement(
                  Array.map(
                    (episode) => <div key=episode##id> (Utils.text(episode##title)) </div>,
                    result##allEpisodes
                  )
                )
              )
            </div>
          }
      )
    </FetchEpisodes>
};