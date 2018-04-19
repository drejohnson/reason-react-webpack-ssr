let styles =
  Css.(
    {
      "icon": [display(inlineBlock), width(rem(1.75)), height(rem(1.75))],
    }
  );

let component = ReasonReact.statelessComponent("Icon");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <Fragment>
      <svg
        version="1.1"
        xmlns="http://www.w3.org/2000/svg"
        style=(ReactDOMRe.Style.make(~height="0", ()))>
        <defs>
          <symbol id="icon-menu" viewBox="0 0 24 24">
            <path
              d="M3 6h18v2.016h-18v-2.016zM3 12.984v-1.969h18v1.969h-18zM3 18v-2.016h18v2.016h-18z"
            />
          </symbol>
          <symbol id="icon-arrow_back" viewBox="0 0 24 24">
            <path
              d="M20.016 11.016v1.969h-12.188l5.578 5.625-1.406 1.406-8.016-8.016 8.016-8.016 1.406 1.406-5.578 5.625h12.188z"
            />
          </symbol>
          <symbol id="icon-search" viewBox="0 0 24 24">
            <path
              d="M9.516 14.016c2.484 0 4.5-2.016 4.5-4.5s-2.016-4.5-4.5-4.5-4.5 2.016-4.5 4.5 2.016 4.5 4.5 4.5zM15.516 14.016l4.969 4.969-1.5 1.5-4.969-4.969v-0.797l-0.281-0.281c-1.125 0.984-2.625 1.547-4.219 1.547-3.609 0-6.516-2.859-6.516-6.469s2.906-6.516 6.516-6.516 6.469 2.906 6.469 6.516c0 1.594-0.563 3.094-1.547 4.219l0.281 0.281h0.797z"
            />
          </symbol>
          <symbol id="icon-google" viewBox="0 0 24 28">
            <path
              d="M12 12.281h11.328c0.109 0.609 0.187 1.203 0.187 2 0 6.844-4.594 11.719-11.516 11.719-6.641 0-12-5.359-12-12s5.359-12 12-12c3.234 0 5.953 1.188 8.047 3.141l-3.266 3.141c-0.891-0.859-2.453-1.859-4.781-1.859-4.094 0-7.438 3.391-7.438 7.578s3.344 7.578 7.438 7.578c4.75 0 6.531-3.406 6.813-5.172h-6.813v-4.125z"
            />
          </symbol>
          <symbol id="icon-twitter" viewBox="0 0 26 28">
            <path
              d="M25.312 6.375c-0.688 1-1.547 1.891-2.531 2.609 0.016 0.219 0.016 0.438 0.016 0.656 0 6.672-5.078 14.359-14.359 14.359-2.859 0-5.516-0.828-7.75-2.266 0.406 0.047 0.797 0.063 1.219 0.063 2.359 0 4.531-0.797 6.266-2.156-2.219-0.047-4.078-1.5-4.719-3.5 0.313 0.047 0.625 0.078 0.953 0.078 0.453 0 0.906-0.063 1.328-0.172-2.312-0.469-4.047-2.5-4.047-4.953v-0.063c0.672 0.375 1.453 0.609 2.281 0.641-1.359-0.906-2.25-2.453-2.25-4.203 0-0.938 0.25-1.797 0.688-2.547 2.484 3.062 6.219 5.063 10.406 5.281-0.078-0.375-0.125-0.766-0.125-1.156 0-2.781 2.25-5.047 5.047-5.047 1.453 0 2.766 0.609 3.687 1.594 1.141-0.219 2.234-0.641 3.203-1.219-0.375 1.172-1.172 2.156-2.219 2.781 1.016-0.109 2-0.391 2.906-0.781z"
            />
          </symbol>
          <symbol id="icon-facebook" viewBox="0 0 16 28">
            <path
              d="M14.984 0.187v4.125h-2.453c-1.922 0-2.281 0.922-2.281 2.25v2.953h4.578l-0.609 4.625h-3.969v11.859h-4.781v-11.859h-3.984v-4.625h3.984v-3.406c0-3.953 2.422-6.109 5.953-6.109 1.687 0 3.141 0.125 3.563 0.187z"
            />
          </symbol>
        </defs>
      </svg>
      <svg
        className=Css.(style(styles##icon))
        style=(ReactDOMRe.Style.make(~fill="#98999a", ()))>
        <use xlinkHref={j|#$name|j} />
      </svg>
    </Fragment>,
};