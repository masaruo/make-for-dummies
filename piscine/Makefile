NAME := a.out
CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ./src/main.o
	$(CC) $(CFLAGS) ./src/main.o -o $(NAME)

./src/main.o : ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -c -o ./src/main.o -I./includes

clean:
	rm -f $(NAME)
	$(RM) ./src/*.o

re: clean
	$(MAKE) --debug=v

.PHONY: clean all re

#この中で、必要ないことしてませんか？
