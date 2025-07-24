# コンパイルの流れ
---
## 1. プリプロセッサ (cpp)：　
### コピペ
   - -I で指定されたパスから *.h ファイルを探す
   - #include の内容を展開
   - マクロ (#define) を展開
   - 条件付きコンパイル (#ifdef など) を処理
   → 中間ファイル (*.i) を生成 `-E`
   - (clang -> `*.bc`)
---
## 2. コンパイラ (cc)：
### 翻訳
   - *.i ファイルを解析
   - 構文チェック
   - 最適化
   → アセンブリコード (*.s) を生成 `-S`
   → オブジェクトコード (*.o) を生成 `-c`
---
## 3. リンカ (ld)：
### 繋ぎ合わせ
   - 複数の *.o ファイルを結合
   - ライブラリとリンク
   → 実行ファイルを生成
---
## complile flags
```
cc -E source.c -o source.i   # プリプロセス
cc -S source.i -o source.s   # アセンブリfile
cc -c source.s -o source.o   # オブジェクトfile生成
cc source.o -o program       # リンク（実行ファイル生成）
or
`-save-temps`
```
---
