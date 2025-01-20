# Make入門
## 育てて学ぶMake
４２東京におけるMake入門講義のためのレポジトリ

### repository
`git@github.com:masaruo/make-for-dummies.git`

### agenda
1. piscineレベル
	* 基礎の振り返り
	* コンパイルの流れ
2. libftレベル
	* `*.c`filesの増加
	* make版`printf`
3. fdfレベル
	* ライブラリ
	* 機能ごとに分けられて複雑になった`./src/**/*.c`
4. minishellレベル
	* `*.h`ファイルをMAKEの依存関係に載せる
	* 状況に応じて変数(i.e. CFLAGS)の値を変える

### オーディエンス対象
* 以下のMakefileが`minishell級`の最終版です。これを見て、学ぶものがあるかご判断ください。
```
NAME := a.out
CC := cc
CPPFLAGS :=	-I./includes \
			-I./fakelibx \
			-MMD -MP
CFLAGS := -Wall -Wextra
SRC := common.c piyo.c hoge.c main.c
OBJDIR := ./obj
LDFLAGS := -Lfakelibx
LDLIBS := -lfake
#OBJ = $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))
#DEP = $(OBJ:%.o=%.d)

vpath %.c ./src:./src/piyo:./src/piyo/hoge

ifeq ($(DEBUG), true)
	CFLAGS += -g3 -O0 -fsanitize=address
	LDFLAGS += -fsanitize=address
else
	CFLAGS += -Werror
endif

OBJ := $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))
DEP := $(OBJ:%.o=%.d)

$(warning OBJ=[$(OBJ)], DEP=[$(DEP)])

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

debug: clean
	$(MAKE) DEBUG=true

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)

.PHONY: clean debug all

-include $(DEP)

```

> [!WARNING]
>今回提示されている例がベストプラクティと言える自信はないので、一例として参照してください。
