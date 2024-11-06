CC = cc
SRC = ft_dico_handler.c ft_hex.c ft_pointer.c ft_printf.c ft_putnbr.c ft_utils.c
OBJ = $(patsubst %.c, %.o, $(SRC))
NAME = libftprintf.a
CFLAGS = -g -Werror -Wextra -Wall

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%.o : %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	
clean : 
	@rm -f $(OBJ) $(B_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
