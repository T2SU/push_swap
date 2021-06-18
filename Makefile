CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

COMMON_DIR = ./srcs/common/
COMMON = \
	list/list_getset \
	list/list_pop \
	list/list_push \
	list/list_rotate \
	list/list_clone \
	list/list_sorted \
	list/list_find_unsorted \
	list/list_swap \
	list/list \
	route/route \
	route/route_apply \
	utils/distinct \
	utils/error \
	utils/print \
	libft/ft_abs \
	libft/ft_atoi_strict \
	libft/ft_isneg \
	libft/ft_itoa \
	libft/ft_max \
	libft/ft_memcpy \
	libft/ft_memmove \
	libft/ft_strlcpy \
	libft/ft_bzero
COMMON_SRC = $(addprefix $(COMMON_DIR), $(addsuffix .c, $(COMMON)))
COMMON_OBJ = $(COMMON_SRC:.c=.o)

PUSH_SWAP_DIR = ./srcs/push_swap/
PUSH_SWAP = \
	main \
	game \
	navigator \
	parser
PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_DIR), $(addsuffix .c, $(PUSH_SWAP)))
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

CHECKER_DIR = ./srcs/checker/
CHECKER = \
	main
CHECKER_SRC = $(addprefix $(CHECKER_DIR), $(addsuffix .c, $(CHECKER)))
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

INC = -I./includes

all : push_swap checker

clean :
	rm -rf $(COMMON_OBJ) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

fclean : clean
	rm -rf push_swap checker

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

common : $(COMMON_OBJ)

push_swap : common $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) -o $@ $(COMMON_OBJ) $(PUSH_SWAP_OBJ)

checker : common $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $@ $(COMMON_OBJ) $(CHECKER_OBJ)

.PHONY: all clean fclean re bonus norme common push_swap checker
