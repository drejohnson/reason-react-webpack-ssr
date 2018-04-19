let styles =
  Css.(
    {
      "nav": [
        display(flexBox),
        flexDirection(row),
        alignItems(center),
        justifyContent(spaceBetween),
      ],
      "navlink": [
        borderLeft(px(1), solid, hex("38393a")),
        marginLeft(rem(0.75)),
        paddingLeft(rem(0.75)),
      ],
      "noBorder": [borderLeft(zero, none, transparent)],
    }
  );

let component = ReasonReact.statelessComponent("Nav");

let make = _children => {
  ...component,
  render: _self =>
    <nav className=(Css.style(styles##nav))>
      <Link
        href="/"
        label="Home"
        className=Css.(
                    style([
                      borderLeft(zero, none, transparent),
                      ...styles##navlink,
                    ])
                  )
      />
      <Link
        href="/about"
        label="About"
        className=Css.(style(styles##navlink))
      />
    </nav>,
};
