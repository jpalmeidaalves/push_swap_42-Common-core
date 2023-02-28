NAME		= push_swap

CC      	= cc 
CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf

LIBFT		= ./libft/libft.a

SRC		= push_swap.c	push.c	rotate.c reverse_rotate.c swap.c utils_list.c validate_args.c	sort_algorithms.c	print_func.c	utils.c	find_out_move.c	utils_sort_big.c
OBJ		= $(SRC:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -g $(CFLAGS) $(SRC) $(LIBFT) -o push_swap

$(LIBFT):
	$(MAKE) -C ./libft

clean: 
	$(MAKE) -C ./libft
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)


re:	fclean all
