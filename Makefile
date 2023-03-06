PUSH_SWAP	= push_swap

CHECKER		= checker

CC      	= cc 
CFLAGS		= -Wall -Werror -Wextra  -g -fsanitize=address

RM		= rm -rf

LIBFT		= ./libft/libft.a

SRC		= push_swap.c	build_stack.c	push.c	rotate.c reverse_rotate.c swap.c utils_list.c validate_args.c	sort_algorithms.c	print_func.c	utils.c		find_out_move_ab.c	utils_sort_big.c	apply_moves.c	find_out_move_ba.c

OBJ		= $(SRC:.c=.o)

SRC_B		= checker.c	build_stack.c	push.c	rotate.c reverse_rotate.c swap.c utils_list.c validate_args.c	sort_algorithms.c	print_func.c	utils.c		find_out_move_ab.c	utils_sort_big.c	apply_moves.c	find_out_move_ba.c

OBJ_B		= $(SRC:.c=.o)


	
all: $(PUSH_SWAP)

bonus: $(CHECKER)

$(PUSH_SWAP): $(OBJ) $(LIBFT) $(SRC)
	$(CC) -g $(CFLAGS) $(SRC) $(LIBFT) -o push_swap

$(LIBFT):
	$(MAKE) -C ./libft

$(CHECKER): $(OBJ_B) $(LIBFT) $(SRC_B)
	$(CC) -g $(CFLAGS) $(SRC_B) $(LIBFT) -o checker
	
clean: 
	$(MAKE) clean -C ./libft 
	$(RM) $(OBJ) 
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(PUSH_SWAP) $(CHECKER) 


re:	fclean all
