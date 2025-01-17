NAME := a.out
CC := cc
CFLAGS := -Wall -Wextra -Werror
INC := -I./includes
SRC := main.c func.c func1.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

vpath %.c src

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
#$(warning compiling target=$@ from $^)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
#$(warning $(OBJDIR))
	mkdir -p $@


$(NAME): $(OBJ)
#$(warning target is $@ and objs are $^)
	$(CC) $^ -o $@

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)

re: clean
	$(MAKE) all

.PHONY: clean re

