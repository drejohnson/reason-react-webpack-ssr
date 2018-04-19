let styles =
  Css.(
    {
      "header": [
        display(flexBox),
        flexDirection(column),
        alignItems(flexStart),
        backgroundColor(hex("1d1e1f")),
        color(hex("7d7e7f")),
        width(pct(100.)),
        height(px(220)),
        paddingLeft(rem(2.)),
        paddingRight(rem(2.)),
        marginBottom(rem(2.5)),
        paddingTop(rem(6.)),
      ],
      "headerSection": [
        fontSize(rem(1.25)),
        fontWeight(400),
        margin(zero),
      ],
      "headerTitle": [
        color(hex("D6D6D7")),
        fontSize(rem(2.25)),
        fontWeight(300),
        lineHeight(1.1666666667),
        textOverflow(ellipsis),
        whiteSpace(nowrap),
        wordWrap(normal),
        overflow(hidden),
      ],
    }
  );

let component = ReasonReact.statelessComponent("ContentHeader");

let make = (~section, ~title, _children) => {
  ...component,
  render: _self =>
    <header className=(Css.style(styles##header))>
      <div className=(Css.style(styles##headerSection))>
        (section ++ "/" |> Utils.text)
      </div>
      <h1 className=(Css.style(styles##headerTitle))>
        (title |> Utils.text)
      </h1>
    </header>,
};