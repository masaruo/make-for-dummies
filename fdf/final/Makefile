NAME := a.out
CC := cc
CPPFLAGS := -I./includes -Ifakeft -Ifakelibx
CFLAGS := -Wall -Wextra -Werror
SRC := main.c process.c parse.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
LDFLAGS := -Lfakelibx
LDLIBS := -lfakelibx

all: $(NAME)

vpath %.c ./src:./src/process:./src/process/parse

$(warning obj=$(OBJ))

$(NAME): $(OBJ) fakeft/libfake.a
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

fakeft/libfake.a:
	$(MAKE) -C fakeft

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(NAME) $(OBJ) $(OBJDIR)
	$(MAKE) clean -C fakeft

re: clean
	$(MAKE) --debug=v

.PHONY: clean all re
