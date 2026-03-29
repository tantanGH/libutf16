# libutf16
UTF-16 to CP932 string conversion library for elf2x68k

MP3のID3tagなどで使われているUTF-16形式の文字列をelf2x68k環境でCP932(ShiftJIS)に変換するためのライブラリです。
ルックアップテーブルによる実装なのでそれなりにメモリを使います。(テーブルサイズ：128KB)

提供される関数は一つだけです。

```
#include <utf16_cp932.h>

void utf16_to_cp932(uint8_t* cp932_buffer, size_t cp932_buffer_bytes, const uint8_t* utf16_buffer, size_t utf16_buffer_bytes);
```

使う時は、サブモジュールとして組み込むのが簡単です。例えばプロジェクト直下にて以下を実行します。

```
git submodule add https://github.com/tantanGH/libutf16.git libs/libutf16
```

以下のようなツリーとなります。

```
my_app/
├── .git/
├── .gitmodules
├── libs/
│   └── libutf16/
│       ├── include/utf16_cp932.h
│       └── lib/libutf16.a
└── src/
    ├── main.c
    └── Makefile
```

ヘッダー検索パスとライブラリ検索パスをMakefile内で
```
-I../libs/libutf16/include
-L../libs/libutf16/lib
```
のように指定し、`-lutf16` でリンクできます。
