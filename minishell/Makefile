NAME := a.out
CC := cc
CFLAGS := -Wall -Wextra -Werror
INC :=	-I./includes \
		-I./fakelibx
SRC := main.c process.c parse.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
LDFLAGS := -Lfakelibx -lfake

vpath %.c src:src/process:src/process/parse

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
#$(warning compiling target=$@ from $^)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
#$(warning $(OBJDIR))
	mkdir -p $@

$(NAME): $(OBJ) ./fakelibx/libfake.a
	$(CC) $(LDFLAGS) $^ -o $@

./fakelibx/libfake.a:
	$(MAKE) -C ./fakelibx

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C ./fakelibx

.PHONY: clean

