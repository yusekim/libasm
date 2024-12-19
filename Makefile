NAME = libasm.a
BONUS_SRCS = ft_list_size.s ft_list_push_front.s
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_list_size.s ft_list_push_front.s
OBJ = $(SRCS:.s=.o)
BONUS_OBJ = $(BONUS_SRCS:.s=.o)
CC = gcc
NASM = nasm
NASMFLAGS = -f macho64
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) test main.o
	rm -f empty_file.txt test_output.txt

re: fclean all

test: all
	$(CC) main.c -L. -lasm -o test -lc
