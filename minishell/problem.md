# level minishell

## issue
```
├── Makefile
├── fakelibx
│   └── ...
├── includes
│   ├── common.h
│   ├── hoge.h
│   ├── main.h
│   └── piyo.h
└── src
    ├── common.c
    ├── main.c
    └── piyo
        ├── hoge
        │   └── hoge.c
        └── piyo.c
```
- [ ] ヘッダーファイルもmakeの追跡対象にしたい
- [ ] コンパイルフラグなど変数を、状況に応じて柔軟に変えたい（開発時は`-Werror`を外すなど）

---
## basic
### -MMD -MP
* `-MMD, --write-user-dependencies` : Write a depfile containing user headers
* `-MP`  Create phony target for each dependency (other than main file)
* `include` 依存関係情報として読み取る
* `-` エラーがあっても無視する（最初のコンパイルは情報がないので、必ず失敗する）
```
CPPFLAGS = ... -MMP -MP
...
-include ($(DEP))
```
---
### ifの使い方
```
ifeq ($(VAR_NAME), true)
<command>
else
<command>
endif
```
`make VAR_NAME=true`

---
### お疲れ様でした
* 皆さんはこれから、皆さんの`MAKE`どう育てますか？もし、迷っているなら、まずは手始めにこんなのどうでしょうか？
	* **`bonus`と`mandatory`を分けるのを楽にしてみるとか？**
	* **`valgrind`** を入れるとか?

> [!Warning]
> A include B && B include A はヘッダーの循環参照で怒られる
> * `*.hpp`で必要ないものは、`*.cpp`でinclude
> * 前方宣言を使用
