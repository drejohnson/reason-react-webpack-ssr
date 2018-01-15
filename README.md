# ReasonReact + Apollo + SSR

> A basic starting point for building universal web apps with ReasonReact.

> Far from refined. Used as a basis to learn ReasonML and POC for server side rendering with ReasonReact

> **Check out the [ReasonReact-Router](https://github.com/drejohnson/reason-webpack-ssr/tree/reason-react-router) branch**

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [ ] PWA - [Workbox](https://developers.google.com/web/tools/workbox/) (**Need to fix**)
* [x] SSR - Server side rendering
* [x] [Webpack - v4.0.0-alpha*](https://webpack.js.org/)
* [x] [Universal Router](https://github.com/kriasoft/universal-router) *(Waiting for Reason Router solution)
* [x] [Reason-Apollo](https://github.com/apollographql/reason-apollo)
* [x] [React Helmet](https://github.com/nfl/react-helmet) bindings

## Quick start

* Use install dependencies: `yarn`
* For dev mode without ssr run `yarn dev` or `npm run dev`, open browser, the app should be running at: http://localhost:8080.
* To build run: `yarn build` or `npm run build`
* To build and run use: `yarn build` or `npm run build` followed by `yarn start` or `npm start`.

## TODO

* [ ] Fix Workbox (It breaks routing)
* [ ] Add "CSS-In-Reason" library. Either [bs-css](https://github.com/SentiaAnalytics/bs-css) or [bs-react-fela](https://github.com/astrada/bs-react-fela).
* [ ] Add [React-Loadable](https://github.com/thejameskyle/react-loadable). Code-Splitting components ...fuck yeah!
* [ ] Use [Razzle](https://github.com/jaredpalmer/razzle) for SSR + Code-Splitting?