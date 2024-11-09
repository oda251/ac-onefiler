## 機能
- `include`ディレクティブを識別し、再帰的に展開しながら、単一の`C/C++`スクリプトファイルを生成します
	- 重複するライブラリは自動的に除外されます
- 「Atcoderで、自作ライブラリを簡便に使用したい」等の利用場面を想定しています
- `define`や`pragma`、`using`等は識別せず、直接書き下すため、重複などによるコンパイルエラーの可能性があります

## 使用例
`sample.cpp`に対して使用する（*）と、下部のコードが得られます
```cpp
// sampe.cpp
#include "sample_grid.hpp"
int main() {
  Grid grid(3);
  Point p(1, 1);
  cout << grid[p] << endl;
  return 0;
}
```
（*） `./ac-compiler sample.cpp`
```cpp
#include <bits/stdc++.h>
#line 1 "library/sample_point.hpp"
class Point {
 public:
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};
#line 1 "library/sample_header.hpp"
using namespace std;
using ll = long long;
#define DEBUG(x) cout << #x << ": " << x << endl;
auto Booster = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
#line 1 "library/sample_grid.hpp"
class Grid {
 private:
  int size_;
  vector<int> data_;

 public:
  Grid(int size) : size_(size), data_(size * size) {
    for (int i = 0; i < size; i++) data_[i] = i;
  }
  int& operator[](const Point& p) { return data_[p.y * size_ + p.x]; }
};
int main() {
  // ~~~~~~~~ 略 ~~~~~~~~~~~
}
```


## 注釈
- ubuntu以外のOSは動作確認しておりません。
- ご指摘、ISSUE、プルリクエスト等大歓迎です。よろしくお願いします。

## 使い方
#### 準備
1. - 任意のディレクトリに当リポジトリをクローン
		- `git clone https://github.com/oda251/ac-onefiler`
2. - (**非linuxユーザ**) `ac-onfiler`のコンパイル
		1. `nlohmann/json`ライブラリのインストール
			- https://github.com/nlohmann/json をクローン
			- `brew`からインストールも可能です
				- `brew install nlohmann-json`
		2. `Makefile`の`NLOHMANN_HEADER_PATH`変数を、インストールした`nlohmann/json`が存在するパスに書き換え
		3. 当リポジトリのルートディレクトリにて、`make`コマンドを実行
   - (**linuxユーザ**) `release`からダウンロードするか、当リポジトリをクローン後`dist`ディレクトリからご利用ください。
     - 恐らくmac含むunux系ユーザもこちらで問題ないと思います。
3. `library`ディレクトリに任意の自作ライブラリを格納
#### 実行方法
```bash
<path_to_ac-compiler> <ソースファイル...>
```
例：
```
$ ./ac-compiler main.cpp
```

## 設定
- `setting.json`を編集します
```json
{
	"library": {
		// 自作ライブラリを格納するディレクトリ
    // 相対パスの場合、実行ファイルが存在するディレクトリを基準にします
		"directory": "library",
	},
	// 出力するファイルの名前
	"output_file": "code.cpp"
}
```
## Tips
- `alias`登録しておくと便利です。作者はコンパイルまで`ac`で行っています
  - 例：`alias ac='f() { <ac-onefilerのパス> $1 && g++ -std=c++17 -o out -I<atcoderライブラリのパス> code.cpp; unset -f f; }; f'`
- ライブラリに`#line`ディレクティブを書いておくと、デバッグ時に便利です

## 使用言語
- C++17
