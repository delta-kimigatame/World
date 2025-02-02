# WorldJSModule
WORLD(https://github.com/mmorise/World)をjavascriptから使用するためにemscriptenを用いてwasmに変換します。

World.JS(https://github.com/YuzukiTsuru/World.JS)をベースにいくつかの改造をしたものです。

# build
Google Colabにnotebook(https://github.com/delta-kimigatame/WorldJSModule/blob/EXPORT_ES6/worldjs_build.ipynb)をアップロードし、実行後生成される`workspace/World.JS.zip`をダウンロードします。

# usage
このコードを直接利用することは想定していません。
この出力成果物を更にTypescriptでライブラリ化したものがありますので、そちらをご利用ください。
TSWorld(https://github.com/delta-kimigatame/TSWorld)