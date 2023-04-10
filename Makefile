PUSH_SWAP	= push_swap

CHECKER		= checker

CC      	= cc 
CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf

LIBFT		= ./libft/libft.a

SRC		= $(wildcard src/*.c)

OBJ		= $(SRC:.c=.o)

SRC_B		= $(wildcard bonus/*.c)

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
