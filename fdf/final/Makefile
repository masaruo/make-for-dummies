NAME := a.out
CC := cc
CPPFLAGS :=	-I./includes \
		-I./fakelibx
CFLAGS := -Wall -Wextra -Werror
SRC := main.c process.c parse.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
# LDFLAGS := -Lfakelibx
# LDLIBS := -lfake

vpath %.c src:src/process:src/process/parse

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
#$(warning compiling target=$@ from $^)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
#$(warning $(OBJDIR))
	mkdir -p $@

$(NAME): $(OBJ) ./fakelibx/libfake.a
	$(CC) $^ -o $@
# $(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

./fakelibx/libfake.a:
	$(MAKE) -C ./fakelibx

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C ./fakelibx

.PHONY: clean

