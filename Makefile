NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ = $(SRC:.s=.o)
CC = gcc
NASM = nasm
NASMFLAGS = -f macho64
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test main.o

re: fclean all

test: all
	$(CC) main.c -L. -lasm -o test -lc
