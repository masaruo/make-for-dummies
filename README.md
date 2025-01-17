# Make入門
## 育てて学ぶMakeクエスト
４２東京におけるMake入門講義のためのレポジトリ

### repository
`git@github.com:masaruo/make-for-dummies.git`

### agenda
1. pisince（スライム級）
	* 基礎の振り返り
	* コンパイルの流れ
2. libft (ゴーレム級)
	* `*.c`filesの増加
	* make版`printf`
3. fdf (メタルキング級)
	* ライブラリ
	* 機能ごとに分けられて複雑になった`./src/*`
4. minishell (ゾーマ級)
	* `*.h`ファイルをMAKEの依存関係に載せる
	* 状況に応じて自在に変数(i.e. CFLAGS)を変える
	* これからの育て方

### オーディエンス対象
* 以下のMakefileが`minishell級`の最終盤なので、これを見て、知らないことがあるので、学びたいと思われる方。
```
NAME := a.out
CC := cc
INC := -I./includes -I./fakelibx
CFLAGS := -Wall -Wextra -MMD -MP
LDFLAGS :=
LIBFT := fakelibx/libfake.a
SRC := common.c piyo.c hoge.c main.c
OBJDIR := ./obj
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
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C ./fakelibx

debug: clean
	$(MAKE) DEBUG=true

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C ./fakelibx

.PHONY: clean debug

-include $(DEP)
```

> [!WARNING]
>私自身、Makeの複雑さにいつも発狂しているので、あまり難しい機能はカバーできません＆＆質問にも答えられません。参加者は優しく見守る心構えが必要かも！？
