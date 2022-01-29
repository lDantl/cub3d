NAME = libft.a

LIST =				ft_isalpha.c	ft_isprint.c		ft_memset.c			ft_strdup.c		ft_strnstr.c\
					ft_atoi.c		ft_itoa.c			ft_putchar_fd.c		ft_strjoin.c	ft_strrchr.c\
					ft_bzero.c		ft_memccpy.c		ft_putendl_fd.c		ft_strlcat.c	ft_strtrim.c\
					ft_calloc.c		ft_memchr.c			ft_putnbr_fd.c		ft_strlcpy.c	ft_substr.c\
					ft_isalnum.c	ft_memcmp.c			ft_putstr_fd.c		ft_strlen.c		ft_tolower.c\
					ft_isascii.c	ft_memcpy.c			ft_strncmp.c		ft_strmapi.c	ft_toupper.c\
					ft_isdigit.c	ft_memmove.c		ft_strchr.c			ft_split.c		
 
LIST_B =			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c		ft_lstlast.c	ft_lstadd_back.c\
					ft_lstdelone.c	ft_lstiter.c		ft_lstclear.c		ft_lstmap.c

OBJ = $(patsubst %.c,%.o,$(LIST))

BONUS_OBJ = $(patsubst %.c,%.o,$(LIST_B))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ 

clean :
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus:
	@make OBJ="$(BONUS_OBJ)" all

.PHONY : all clean fclean re bonus