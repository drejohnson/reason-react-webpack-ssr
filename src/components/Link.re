open Utils;

let component = ReasonReact.statelessComponent("Link");

let make = (~href, ~label, ~className=label |> Js.String.toLowerCase, _children) => {
  ...component,
  render: (self) =>
    <a
      href
      className
      onClick=(
        self.handle(
          (event, _self) => {
            ReactEventRe.Mouse.preventDefault(event);
            ReasonReact.Router.push(href)
          }
        )
      )>
      (label |> text)
    </a>
};