# level libft

## issue
```
.
├── includes
│   └── libft.h
├── Makefile
├── src
　　  ├── func1.c
 　　 ├── func.c
  　　└── main.c

```
* multiple `*.c` files
* `.o` fileをまとめて`src`が汚れるのを避けよう
* `how to printf?`

## basic
---
### vpath
`vpath %.c src`
### pattern rule
`OBJ := $(SRC:%.c=%.o)`
`OBJ := $(SRC:%.c=$(OBJDIR)/%.o)` or `$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))`
```
%.o : %.c
<tab> commands
```
>[!TIP]
>`suffix ruleというのもあるが旧式なのでお勧めせず。`
>```
>.c.o:
><tab> commands
>```

### 自動変数
`%@`	ターゲットファイル
`%<`	最初の依存ファイル
`%^`	全ての依存ファイルのリスト
`%?`	libftように調べてみて？

### printf
* make版printf: `$(warning $(<var_name>))`

### etc
* order only 前提条件 `| <prerequisite>`

* 依存関係を考える
	* headerfileに詰め込みすぎてませんか？
	* CPPになるとヘッダーファイルは強制的に分かれるので、循環参照など気をつけて

