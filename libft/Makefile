NAME := a.out
CC := cc
CPPFLAGS := -I./includes
CFLAGS := -Wall -Wextra -Werror
SRC := main.c func.c func1.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

vpath %.c src

all: $(NAME)

$(warning OBJ:[$(OBJ)])

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@


$(NAME): $(OBJ)
# $(warning target is [$@] and objs are [$^] and OBJ is [$(OBJ)])
# @echo "shell target <$@> and objs are <$^> and OBJ is <$(OBJ)>"
	$(CC) $^ -o $@

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)

re: clean
	$(MAKE) all

.PHONY: clean re all

