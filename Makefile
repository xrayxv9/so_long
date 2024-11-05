CC = cc
PARSING = parsing/certificate_map.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/node_handle.c parsing/parsing.c parsing/text_handle.c
PRINTF = printf/libftprintf.a
SRC = $(PARSING) $(PRINTF)
OBJ = $(SRC:%.c=o_files/%.o)
NAME = so_long.a
CFLAGS = -g -Werror -Wextra -Wall

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $@ $^ $(OBJ)

o_files/%.o : %.c
	$(CC) -o $@ $< -c $(CFLAGS)
	
clean : 
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
