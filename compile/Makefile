NAME := a.out
SRC := main.c
CC := cc
CFLAGS = -Wall

$(NAME): main.o
	$(CC) $^ -o $@

main.o: main.s
	$(CC) $(CFLAGS) -c $^ -o $@

main.s: main.i
	$(CC) $(CFLAGS) -S $^ -o $@

main.i: main.c
	$(CC) $(CFLAGS) -E $^ -o $@

clean:
	$(RM) *.o a.out *.i *.s

.PHONY: clean
