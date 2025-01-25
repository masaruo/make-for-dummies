NAME := a.out
SRC := main.c
CC := gcc
CFLAGS = -Wall

$(NAME): main.o
	$(CC) $^ -o $@

main.o: main.s
	$(CC) $(CFLAGS) -c $^ -o $@

main.s: main.i
	$(CC) $(CFLAGS) -S $^ -o $@

main.i: main.c
	$(CC) $(CFLAGS) -E $^ -o $@

verbose:
	cc -save-temps -v main.c -o a.out

clean:
	$(RM) *.o a.out *.i *.s *.bc

.PHONY: clean
