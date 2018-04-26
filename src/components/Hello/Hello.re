module HelloQuery = [%graphql
  {|
    query getHello($name: String!) {
      hello(name: $name)
    }
|}
];

module Query = ReasonApollo.CreateQuery(HelloQuery);

let styles =
  Css.(
    {
      "hello": [
        display(flexBox),
        flexDirection(column),
        alignItems(flexStart),
        color(hex("7d7e7f")),
        paddingLeft(rem(2.)),
        paddingRight(rem(2.)),
      ],
    }
  );

let component = ReasonReact.statelessComponent("Hello");

let make = (~name, _children) => {
  ...component,
  render: _self => {
    let helloQuery = HelloQuery.make(~name, ());
    <Fragment>
      <div className=(Css.style(styles##hello))>
        <Query variables=helloQuery##variables>
          ...(
               ({result}) =>
                 switch (result) {
                 | NoData => "No Data" |> Utils.text
                 | Error(_) => "Something Went Wrong" |> Utils.text
                 | Loading => <Placeholder />
                 | Data(result) =>
                   switch (result##hello) {
                   | None => <h1> ("Hello World" |> Utils.text) </h1>
                   | Some(name) => <h1> (name |> Utils.text) </h1>
                   }
                 }
             )
        </Query>
      </div>
    </Fragment>;
  },
};