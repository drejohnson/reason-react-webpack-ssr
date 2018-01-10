const fs = require('fs')
const path = require('path')
const nodeExternals = require('webpack-node-externals')
const webpack = require('webpack')
const config = require('./config')

const isPROD = process.env.NODE_ENV === 'production'

module.exports = {
  mode: process.env.NODE_ENV || 'development',
  name: 'server',
  target: 'node',
  node: {
    __dirname: false
  },
  entry: config.resolveApp('lib/js/src/server.bs.js'),
  output: {
    path: config.resolveApp('dist/server'),
    filename: 'index.js',
    libraryTarget: 'commonjs2'
  },
  module: {
    rules: [
      {
        exclude: /node_modules/,
        test: /\.js$/,
        use: {
          loader: 'babel-loader',
          options: {
            cacheDirectory: true
          }
        }
      }
    ]
  },
  plugins: [
    new webpack.DefinePlugin({
      APP_BUNDLE: JSON.stringify(
        isPROD
          ? require(config.resolveApp('dist/asset-manifest.json'))['client.js']
          : 'static/js/client.js'
      ),
      VENDOR_BUNDLE: JSON.stringify(
        isPROD
          ? require(config.resolveApp('dist/asset-manifest.json'))['vendors.js']
          : 'static/js/vendors.js'
      )
    })
  ],
  externals: [nodeExternals()]
}
