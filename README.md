# Reason Parcel SSR

> A basic starting point for building universal web apps with ReasonReact bundled with Parcel.

> Far from refined. Used as a basis to learn ReasonML and POC for server side rendering with ReasonReact and Parcel

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [ ] PWA - [Workbox](https://developers.google.com/web/tools/workbox/) (**Need to fix**)
* [x] SSR - Server side rendering
* [x] [Webpack - v4.0.0-alpha*](https://webpack.js.org/)
* [x] [Universal Router](https://github.com/kriasoft/universal-router) *(Waiting for Reason Router solution)
* [x] [React Helmet](https://github.com/nfl/react-helmet) bindings

## Quick start

* Use install dependencies: `yarn`
* For dev mode without ssr run `yarn dev` or `npm run dev`, open browser, the app should be running at: http://localhost:8080.
* To build run: `yarn build` or `npm run build`
* To build and run use: `yarn build` or `npm run build` followed by `yarn start` or `npm start`. (**For production prepend NODE_ENV=production**)

## TODO

* [ ] **Fix Production build (getting mime type errors on js files)**
* [ ] Fix Workbox (It breaks routing)
* [ ] Add "CSS-In-Reason" library. Either [bs-css](https://github.com/SentiaAnalytics/bs-css) or [bs-react-fela](https://github.com/astrada/bs-react-fela).
* [ ] Add [React-Loadable](https://github.com/thejameskyle/react-loadable). Code-Splitting components ...fuck yeah!