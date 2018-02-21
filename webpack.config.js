const webpack = require('webpack')
const fs = require('fs')
const path = require('path')

const AssetsManifestPlugin = require('webpack-assets-manifest')
const { ReactLoadablePlugin } = require('react-loadable/webpack')

const appDirectory = fs.realpathSync(process.cwd())

const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

const isProd = process.env.NODE_ENV === 'production'

const client = {
  mode: process.env.NODE_ENV || 'development',
  name: 'client',
  entry: {
    client: './src/Client.bs.js'
  },
  output: {
    path: resolveApp('dist'),
    filename: `static/js/[name]${isProd ? '.[chunkhash:8]' : ''}.js`,
    chunkFilename: `static/js/[name]${isProd ? '.[chunkhash:8]' : ''}.js`,
    publicPath: '/'
  },
  plugins: [new AssetsManifestPlugin({ output: 'assets.json' })],
  resolve: {
    extensions: ['.js', '.bs.js']
  },
  optimization: {
    splitChunks: {
      cacheGroups: {
        commons: {
          chunks: 'initial',
          minChunks: 3,
          minSize: 0
        },
        vendor: {
          test: /node_modules/,
          chunks: 'initial',
          name: 'vendor',
          enforce: true
        }
      }
    },
    occurrenceOrder: true
  },
  node: {
    dgram: 'empty',
    fs: 'empty',
    net: 'empty',
    tls: 'empty',
    child_process: 'empty'
  }
}

module.exports = client
