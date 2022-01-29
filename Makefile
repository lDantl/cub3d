NAME			=	cub3d

#NAMEBON			=	cub3d_bonus

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I libft/ -g

LIBFT			=	libft/libft.a

HEADER			=	src/cub3d.h libft/libft.h gnl/get_next_line.h

GNL				=	get_next_line.c get_next_line_utils.c

#MLX				= 	libmlx.a

#LIBS			= 	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm

SRCS				=	main.c ft_error.c free_all.c

SRC				=	$(addprefix src/, $(SRCS)) \
					$(addprefix gnl/, $(GNL))

OBJ				=	$(patsubst %.c,%.o,$(SRC))

LIB_DIR			=	libft/

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJ) $(HEADER)
	@echo "\n"
	@echo "\033[0;32mCompiling cub3d..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ) ${LIBS}
	@echo "\n\033[0mDone !"

$(LIBFT)		:
	@$(MAKE) -sC libft/

%.o				:		%.c
	@printf "\033[0;33mGenerating cub3d objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean			:
	@$(MAKE) -sC $(LIB_DIR) clean
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean			: clean
	@rm -f $(LIBFT)
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re				:	fclean all

norm:
	@norminette $(SRC) cub3d.h

.PHONY: all clean fclean re test norm bonus