open UniversalRouter;

let handlers = (redirect) => [|
  route(~path="", ~action=() => <Home redirect />, ()),
  route(~path="/about", ~action=() => <About redirect />, ()),
  route(~path="(.*)", ~action=() => <NotFound redirect />, ())
|];