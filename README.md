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
* 以下のMakefileが`minishell級`の最終版です。これを見て、知らないから学びたいと思われる方が対象です。
```
NAME := a.out
CC := cc
CPPFLAGS :=	-I./includes \
			-I./fakelibx
CFLAGS := -Wall -Wextra -MMD -MP
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

.PHONY: clean debug

-include $(DEP)

```

> [!WARNING]
>私自身、Makeの複雑さにいつも`orz`しているので、あまり難しい機能はカバーできません＆＆質問にも答えらないものが多いです。参加者は優しく見守る心構えが必要かも！？
