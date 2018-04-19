Css.(
  global("html", [backgroundColor(hex("262728")), minHeight(vh(100.))]),
  global("body", [backgroundColor(hex("262728")), color(hex("aaabac"))]),
  global("a, a:hover", [color(currentColor), textDecoration(none)]),
  global("a:active, a:hover", [outline(zero, none, transparent)]),
  global("button:focus", [outline(zero, none, transparent)]),
  global(
    "icon",
    [display(inlineBlock), width(rem(1.)), height(rem(1.))],
  ),
);

ReactDOMRe.hydrateToElementWithId(
  <ReasonApollo.Provider client=Apollo.client>
    <App />
  </ReasonApollo.Provider>, 
  "root"
);

if (Utils.moduleHot) {
  Utils.moduleHot |> Utils.accept;
};