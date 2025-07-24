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
- [ ] multiple `*.c` files
- [ ] `.o` fileをまとめて`src`が汚れるのを避けよう
- [ ] `how to printf?`

## basic
---
### vpath
`vpath %.c src`
### pattern rule
```
%.o : %.c
<tab> commands
```
`OBJ := $(SRC:%.c=%.o)`
`OBJ := $(SRC:%.c=$(OBJDIR)/%.o)` or `$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))`
> [!TIP]
>`suffix ruleというのもあるが旧式なのでお勧めせず。`
>```
>.c.o:
><tab> commands
>```

### 自動変数
`$@`	ターゲットファイル
`$<`	最初の依存ファイル
`$^`	全ての依存ファイルのリスト
`$?`	libft用に調べてみては？

### printf
* make版printf: `$(warning $(<var_name>))`
* `--debug=<FLAG>` `b` basic, `v` verbose, `a` all

### etc
* order only 前提条件 `| <prerequisite>`
