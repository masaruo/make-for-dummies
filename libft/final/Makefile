NAME := a.out
CC := cc
CPPFLAGS := -I./includes
CFLAGS := -Wall -Wextra -Werror
SRC := main.c func.c func1.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

vpath %.c ./src

$(warning obj=$(OBJ))

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(NAME) $(OBJ) $(OBJDIR)

re: clean
	$(MAKE) --debug=v

.PHONY: clean all re

#この中で、必要ないことしてませんか？
