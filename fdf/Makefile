NAME := a.out
CC := cc
CPPFLAGS :=	-I./includes \
			-I./fakelibx \
			-I./fakeft
CFLAGS := -Wall -Wextra -Werror
SRC := main.c process.c parse.c
OBJDIR := ./obj
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
LDFLAGS := -Lfakelibx
LDLIBS := -lfakelibx

vpath %.c src:src/process:src/process/parse

all: $(NAME)

$(OBJDIR)/%.o : %.c | $(OBJDIR)
#$(warning compiling target=$@ from $^)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
#$(warning $(OBJDIR))
	mkdir -p $@

$(NAME): $(OBJ) ./fakeft/libfake.a
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

./fakeft/libfake.a:
	$(MAKE) -C ./fakeft

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)
	$(MAKE) clean -C ./fakeft

.PHONY: all clean

