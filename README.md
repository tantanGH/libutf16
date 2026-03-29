# libutf16
UTF-16 to CP932 string conversion library for elf2x68k

MP3のID3tagなどで使われているUTF-16形式の文字列をCP932(ShiftJIS)に変換するためのライブラリです。
ルックアップテーブルによる実装なのでそれなりにメモリを使います。(テーブルサイズ：128KB)

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
│       ├── include/
│       └── lib/libutf16.a
└── src/
    ├── main.c
    └── Makefile
```

ヘッダー検索パスとライブラリ検索パスをMakefile内で
```
-I../libs/libj/include
-L../libs/libj/lib
```
のように指定し、`-lutf16` でリンクできます。
