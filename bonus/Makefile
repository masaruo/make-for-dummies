NAME := exe
CC := cc
INC := -I./includes -I./libft
CFLAGS := -Wall -Wextra -MMD -MP
LDFLAGS :=
LIBFT := ./libft/libft.a
SRC := common.c piyo.c hoge.c
MANDATORY_SRC := main.c
BONUS_SRC := main_bonus.c
OBJDIR := ./obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))
DEP = $(OBJ:%.o=%.d)

vpath %.c ./src:./src/piyo:./src/piyo/hoge

ifeq ($(BONUS), true)
	NAME := $(NAME)_bonus
	SRC += $(BONUS_SRC)
else
	SRC += $(MANDATORY_SRC)
endif

ifeq ($(DEBUG), true)
	CFLAGS += -g -fsanitize=address
	LDFLAGS += -fsanitize=address
else
	CFLAGS +=
endif

$(warning OBJ=[$(OBJ)], DEP=[$(DEP)])

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C ./libft

bonus:
	$(MAKE) BONUS=true

debug: clean
	$(MAKE) DEBUG=true

debugbonus: clean
	$(MAKE) DEBUG=true BONUS=true

clean:
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	$(RM) -r $(OBJDIR)
	$(MAKE) fclean -C ./libft

.PHONY: clean debug bdebug

-include $(DEP)
