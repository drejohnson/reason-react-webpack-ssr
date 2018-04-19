open Types;

let server =
  GraphqlYoga.createGraphQLServer(
    ~typeDefs="./src/schema.graphql",
    ~resolvers=Resolvers.resolvers,
    (),
  );

server
|> GraphqlYoga.start(() =>
     Js.log("Server is running on http://localhost:4000")
   );
