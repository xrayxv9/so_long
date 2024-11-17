NAME = so_long

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

INC_DIR = includes
INCS = -I lib/get_next_line -I lib/MacroLibX/$(INC_DIR)

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

#MLX_DIR := lib/MacroLibX
#MLX := $(MLX_DIR)/libmlx.so

MLX_DIR := lib/MacroLibX
MLX := $(MLX_DIR)/libmlx.so

PRINTF_DIR = lib/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = lib/get_next_line/
GNL = $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

PARSING_PATH = parsing/
OBJ_PATH = obj/
GRAPHIC_PATH =  graphics/

PARSING = certificate_map.c node_handle.c parsing.c text_handle.c flood_fill.c main.c core.c hook.c

PARSINGS = $(addprefix $(PARSING_PATH), $(PARSING))
OBJ = $(PARSING:.c=.o) 
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)
	@echo "$(BLUE)Compilation terminée"
	@echo "$(RESET)"

#$(MLX):
#	make --no-print-directory -C $(MLX_DIR) -s -j all

$(PRINTF):
	@make --no-print-directory -C $(PRINTF_DIR)

$(MLX):
	@make --no-print-directory -C $(MLX_DIR) -s -j all

$(NAME): $(PRINTF) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(GNL) $(PRINTF) -o $@ `sdl2-config --cflags --libs` $(MLX)

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@echo "$(RED)Suppression des fichiers objets..."
	@rm -rf $(OBJ_PATH)
	@make --no-print-directory -C $(MLX_DIR) -s -j clean
	@make --no-print-directory -C $(PRINTF_DIR) fclean
	@echo "$(RED)"
	@echo "$(RESET)"

fclean: clean
	@echo "$(RED)Suppression de l'exécutable..."
	@make --no-print-directory -C $(MLX_DIR) -s -j fclean
	@rm -f $(NAME)
	
re: fclean all
	@echo "$(GREEN)Réinitialisation terminée"
	@echo "$(RESET)"

.PHONY: all clean fclean re
