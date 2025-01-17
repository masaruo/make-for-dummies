NAME := libfake.a

all: $(NAME)

$(NAME): fake.o
	ar rcs $@ $?

fake.o: fake.c
	cc -c $< -o $@

clean:
	$(RM) $(NAME)
	$(RM) fake.o

.PHONY: clean

