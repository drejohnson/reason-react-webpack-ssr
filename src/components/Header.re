let styles =
  Css.(
    {
      "header": [
        position(fixed),
        left(zero),
        top(zero),
        display(flexBox),
        flexDirection(column),
        backgroundColor(hex("262728")),
        boxShadow(~y=px(3), rgba(0, 0, 0, 0.08)),
        borderBottom(px(1), solid, rgba(0, 0, 0, 0.2)),
        width(pct(100.)),
        minHeight(rem(3.75)),
        paddingLeft(rem(2.)),
        paddingRight(rem(2.)),
        transform(translateZ(zero)),
        zIndex(100),
      ],
      "headerInner": [
        display(flexBox),
        flexDirection(row),
        justifyContent(spaceBetween),
        marginTop(rem(1.)),
        marginBottom(rem(1.)),
      ],
      "logo": [fontSize(rem(1.25)), fontWeight(400), margin(zero)],
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
      "btn": [
        display(flexBox),
        flexDirection(row),
        alignItems(center),
        justifyContent(center),
        color(hex("98999a")),
        textDecoration(none),
        backgroundColor(transparent),
        border(zero, none, transparent),
        outline(zero, none, transparent),
        transform(translate(zero, zero)),
        overflow(hidden),
        cursor(`pointer),
      ],
      "search": [
        height(zero),
        overflow(hidden),
        transitionProperty("height"),
        transitionDuration(160),
        transitionTimingFunction(easeInOut),
      ],
      "searchOpen": [height(rem(4.))],
    }
  );

let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <header className=(Css.style(styles##header))>
        <div className=(Css.style(styles##headerInner))>
          <h1 className=(Css.style(styles##logo))>
            <a href="/"> ("ReasonReact Fullstack" |> Utils.text) </a>
          </h1>
          <nav className=(Css.style(styles##nav))>
            <Link
              href="/about"
              label="About"
              className=Css.(style(styles##navlink))
            />
          </nav>
        </div>
      </header>
    </Fragment>,
};
