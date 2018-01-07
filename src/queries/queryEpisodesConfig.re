[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Write graphql query passing a limit as variable */
let query =
  [@bs] gql({|
  query allEpisodes {
    allEpisodes {
      id
      title
    }
  }
|});

/* Describe the result type */
type episodes = {. "id": string, "title": string};

type data = {. "allEpisodes": array(episodes)};

type response = data;

/* Optional: Define the type of variables you give
     We also have a `from` variable coming from the props
   */
type variables;