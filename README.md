# ReasonReact Fullstack Graphql SSR

> A basic starting point for building universal web apps with ReasonReact.

> Far from refined. Used as a basis to learn ReasonML and POC for server side rendering and code-spliting with ReasonReact

> Build automation tools based heavily off of [react-starter-kit](https://github.com/kriasoft/react-starter-kit)

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [x] [Webpack](https://webpack.js.org/)
* [x] SSR - Server side rendering
* [x] [React Helmet](https://github.com/nfl/react-helmet)
* [x] Code Splitting - [Reason Loadable](https://github.com/kMeillet/reason-loadable)
* [ ] [Reason Apollo](https://github.com/apollographql/reason-apollo) (SSR not working)
* [ ] PWA - [Workbox](https://developers.google.com/web/tools/workbox/)

## Quick start

* Install dependencies: run `yarn` in project root then `cd server` and run `yarn`
* For frontend dev server: run `yarn start` or `npm start`, from project root. The app should be running at: http://localhost:8080.
* For graphql server: in seperate terminal tab/window `cd server` and run `yarn bsb` or `npm run bsb` followed by `yarn start` or `npm start`, the server should be running at: http://localhost:4000.
* To build frontend run: `yarn build` or `npm run build` from project root. Run `yarn start` or `npm start` to start app.

## TODO

* [ ] Add offline capabilities (service workers) [Workbox](https://developers.google.com/web/tools/workbox/)
