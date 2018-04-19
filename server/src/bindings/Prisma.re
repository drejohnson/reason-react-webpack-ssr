type fragmentReplacements;

type prismaProps = {
  .
  "fragmentReplacements": Js.Nullable.t(fragmentReplacements),
  "typeDefs": Js.Nullable.t(string),
  "endpoint": Js.Nullable.t(string),
  "secret": Js.Nullable.t(string),
  "debug": Js.Nullable.t(Js.boolean),
};

[@bs.module "prisma-binding"] [@bs.new]
external makePrisma : prismaProps => 'a = "Prisma";

let createPrisma =
    (
      ~fragmentReplacements=?,
      ~typeDefs=?,
      ~endpoint=?,
      ~secret=?,
      ~debug=?,
      (),
    ) => {
  let prismaOptions = {
    "fragmentReplacements": Js.Nullable.fromOption(fragmentReplacements),
    "typeDefs": Js.Nullable.fromOption(typeDefs),
    "endpoint": Js.Nullable.fromOption(endpoint),
    "secret": Js.Nullable.fromOption(secret),
    "debug": Js.Nullable.fromOption(debug),
  };
  makePrisma(prismaOptions);
};
