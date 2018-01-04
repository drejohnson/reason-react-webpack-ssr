const webpack = require('webpack')
const path = require('path')

const ManifestPlugin = require('webpack-manifest-plugin')
const config = require('./config')

const isPROD = process.env.NODE_ENV === 'production'

const client = {
  name: 'client',
  cache: true,
  entry: {
    client: isPROD
      ? config.resolveApp('src/client.bs.js')
      : [
        'react-hot-loader/patch',
        `webpack-hot-middleware/client?reload=true`,
        config.resolveApp('src/client.bs.js')
      ]
  },
  output: {
    path: path.join(__dirname, 'dist'),
    filename: `static/js/[name]${isPROD ? '.[chunkhash:8]' : ''}.js`,
    chunkFilename: `static/js/[name]${isPROD ? '.[chunkhash:8]' : ''}.js`,
    publicPath: '/'
  },
  plugins: [
    ...(isPROD ? [] : [new webpack.HotModuleReplacementPlugin()]),
    new ManifestPlugin({
      fileName: 'asset-manifest.json'
    }),
    new webpack.optimize.CommonsChunkPlugin({
      name: 'vendors',
      minChunks: module => /node_modules/.test(module.resource)
    }),
    new webpack.optimize.CommonsChunkPlugin({
      async: 'vendors',
      children: true,
      minChunks: 3
    }),
    new webpack.EnvironmentPlugin({
      PUBLIC_URL: JSON.stringify(path.resolve(__dirname, 'dist'))
    })
  ],
  optimization: {
    occurrenceOrder: true
  },
  performance: {
    hints: false
  },
  node: {
    dgram: 'empty',
    fs: 'empty',
    net: 'empty',
    tls: 'empty',
    child_process: 'empty'
  }
  // recordsOutputPath: path.join(__dirname, 'build', 'records.json')
}

module.exports = client
