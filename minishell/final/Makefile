NAME := a.out
CC := cc
CPPFLAGS :=	-I./includes \
			-I./fakelibx \
			-MMD -MP
CFLAGS := -Wall -Wextra
SRC := common.c piyo.c hoge.c main.c
OBJDIR := ./obj
LDFLAGS := -Lfakelibx
LDLIBS := -lfake
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
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

debug: clean
	$(MAKE) DEBUG=true

clean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)

.PHONY: clean debug

-include $(DEP)
