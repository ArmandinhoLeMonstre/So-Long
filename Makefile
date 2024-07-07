NAME = so_long


CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = checkepc ft_backtrack get_next_line ft_split get_next_line_utils parsing utilsparsing affichage keyhook ft_printf ft_hex ft_fonctions utilskey

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

HEAD = ./include/

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	@$(CC) $(CFLAGS) $(MINIFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all