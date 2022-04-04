NAME			=	cub3d

NAMEBONUS 		= cub3dbonus

CC				=	gcc -g

CFLAGS			=	-Wall -Wextra -Werror -I libft/

LIBFT			=	libft/libft.a

HEADER			=	include/cub3d.h libft/libft.h gnl/get_next_line.h

GNL				=	get_next_line.c get_next_line_utils.c

MLX				= 	minilibx_opengl_20191021/libmlx.a

SRCS			=	cub3d.c						free_all.c					ft_error.c\
					parser_1.c					parser_2.c					parser_3.c							parser_4.c\
					raycasting/image.c			raycasting/keycode.c		raycasting/map_fill_image.c				raycasting/raycasting_the_third_part.c\
					raycasting/raycasting.c		raycasting/point.c			raycasting/raycasting_second_part.c		raycasting/utils.c
					
SRC				=	$(addprefix src/, $(SRCS)) \
					$(addprefix gnl/, $(GNL))

OBJ				=	$(patsubst %.c,%.o,$(SRC))

LIB_DIR			=	libft/

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJ) $(HEADER)
	@echo "\n"
	@echo "\033[0;32mCompiling cub3d..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ) -framework OpenGL -framework AppKit -lmlx $(MLX)
	@echo "\n\033[0mDone !"

$(LIBFT)		:
	@$(MAKE) -sC libft/

bonus			:	$(LIBFT) $(OBJ) $(HEADER)
	@echo "\n"
	@echo "\033[0;32mCompiling cub3d..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAMEBONUS) $(OBJ) -framework OpenGL -framework AppKit -lmlx $(MLX)
	@echo "\n\033[0mDone !"


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
	@rm -f $(NAMEBONUS)
	@echo "\033[0m"

re				:	fclean all

norm:
	@norminette $(SRC) include/cub3d.h

.PHONY: all clean fclean re test norm bonus