NAME = libasm.a
NAME_BONUS = libasm_bonus.a
BONUS_SRCS = ft_list_size_bonus.s ft_list_push_front_bonus.s ft_atoi_base_bonus.s
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(BONUS_OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) test main.o
	rm -f empty_file.txt test_output.txt

re: fclean all

test: all
	$(CC) main.c -L. -lasm -o test -lc

test_bonus: bonus
	$(CC) main.c -L. -lasm_bonus -o test -lc
