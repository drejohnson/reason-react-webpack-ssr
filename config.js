const fs = require('fs')
const path = require('path')

const appDirectory = fs.realpathSync(process.cwd())

module.exports = {
  resolveApp: relativePath => path.resolve(appDirectory, relativePath)
}
