const webpack = require('webpack')
const fs = require('fs')
const path = require('path')

const nodeExternals = require('webpack-node-externals')

const appDirectory = fs.realpathSync(process.cwd())

const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

const isProd = process.env.NODE_ENV === 'production'

const server = {
  mode: process.env.NODE_ENV || 'development',
  name: 'server',
  target: 'node',
  entry: {
    server: resolveApp('lib/js/src/Server.bs.js')
  },
  output: {
    path: resolveApp('dist/server'),
    filename: 'index.js',
    libraryTarget: 'commonjs2'
  },
  plugins: [
    new webpack.DefinePlugin({
      APP_BUNDLE: JSON.stringify(
        isProd
          ? require(config.resolveApp('dist/assets.json'))['client.js']
          : 'static/js/client.js'
      ),
      VENDOR_BUNDLE: JSON.stringify(
        isProd
          ? require(config.resolveApp('dist/assets.json'))['vendor.js']
          : 'static/js/vendor.js'
      )
    })
  ],
  resolve: {
    extensions: ['.js', '.bs.js']
  },
  optimization: {
    occurrenceOrder: true
  },
  externals: [nodeExternals()]
}

module.exports = server
