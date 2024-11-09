## 機能
- `include`ディレクティブを識別し、再帰的に展開しながら、単一の`C/C++`スクリプトファイルを生成します
	- 重複するライブラリは自動的に除外されます
- 「Atcoderで、自作ライブラリを簡便に使用したい」等の利用場面を想定しています
- `define`や`pragma`、`using`等は識別せず、直接書き下すため、重複する可能性があります

## 注釈
- ubuntu以外のOSをご利用の方は、お手数ですがコンパイルからお願いします。
- プルリクエスト大歓迎です。よろしくお願いします。

## 使い方
#### 準備
1. `git clone https://github.com/oda251/ac-onefiler`
2. (**非ubuntuユーザ**) `ac-onfiler`のコンパイル
	- https://github.com/nlohmann/json をクローン
		- `brew`からインストールも可能です
   	- `brew install nlohmann-json`
	- `Makefile`の`NLOHMANN_HEADER_PATH`変数を、インストールした`nlohmann/json`が存在するパスに書き換え
	- 当リポジトリのルートディレクトリにて、`make`コマンドを実行
- (**ubuntuユーザ**) `dist`ディレクトリのコンパイル済みファイルを使用できます

3. `ac-onfiler`、`setting.json`、`library`ディレクトリを同じ階層に配置
4. `library`ディレクトリに自作ライブラリを格納
#### 実行方法
```bash
./ac-onfiler <ソースファイル...>
```

## 設定
- `setting.json`を編集します
```json
{
	"library": {
		// 自作ライブラリを格納するディレクトリ
		"directory": "library",
	},
	// 出力するファイルの名前
	"output_file": "code.cpp"
}
```

## 使用言語
- C++17
