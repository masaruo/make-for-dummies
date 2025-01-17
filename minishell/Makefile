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
	$(RM) $(NAME)_bonus
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C ./fakelibx

.PHONY: clean debug

-include $(DEP)
