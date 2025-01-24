NAME := a.out
CC := cc
CPPFLAGS := -I./includes -Ifakelibx -MMD -MP
CFLAGS := -Wall -Wextra
SRC := main.c common.c piyo.c hoge.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
DEP := $(OBJ:%.o=%.d)
LDFLAGS := -Lfakelibx
LDLIBS := -lfake

vpath %.c ./src:./src/piyo:./src/piyo/hoge

ifeq ($(DEBUG), true)
CFLAGS += -g -O0 -fsanitize=address
LDFLAGS += -fsanitize=address
else
CFLAGS += -Werror
endif

all: $(NAME)

$(warning obj=$(OBJ))

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(NAME) $(OBJ) $(OBJDIR)

re: clean
	$(MAKE) --debug=v

debug: clean
	$(MAKE) DEBUG=true

.PHONY: clean all re

-include $(DEP)
