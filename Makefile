# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeboose <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 11:28:59 by adeboose          #+#    #+#              #
#    Updated: 2024/11/01 11:29:03 by adeboose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

INC_DIR = includes
INCS = -I ./$(INC_DIR) -I lib/MacroLibX/$(INC_DIR) -I lib/Get_next_line -I lib/libft/$(INC_DIR)

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

MLX_DIR := lib/MacroLibX
MLX := $(MLX_DIR)/libmlx.so

LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

GNL_DIR := lib/Get_next_line/
GNL := $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

SRC_PATH = src/
OBJ_PATH = obj/

SRC := main.c game.c graphics.c map.c error.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)
	@echo "$(BLUE)=== Compilation terminée ==="
	@echo " █████╗ ██╗     ██╗     "
	@echo "██╔══██╗██║     ██║     "
	@echo "███████║██║     ██║     "
	@echo "██╔══██║██║     ██║     "
	@echo "██║  ██║███████╗███████╗"
	@echo "╚═╝  ╚═╝╚══════╝╚══════╝"
	@echo "$(RESET)"

$(MLX):
	make --no-print-directory -C $(MLX_DIR) -s -j all

$(LIBFT):
	make --no-print-directory -C $(LIBFT_DIR) -s -j all

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(GNL) -o $@ $(LIBFT) -lSDL2 $(MLX)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@echo "$(RED)=== Suppression des fichiers objets... ==="
	rm -rf $(OBJ_PATH)
	make --no-print-directory -C $(LIBFT_DIR) -s -j clean
	make --no-print-directory -C $(MLX_DIR) -s -j clean
	@echo "$(RED)"
	@echo " ▄▄· ▄▄▌  ▄▄▄ . ▄▄▄·  ▐ ▄ "
	@echo "▐█ ▌▪██•  ▀▄.▀·▐█ ▀█ •█▌▐█"
	@echo "██ ▄▄██▪  ▐▀▀▪▄▄█▀▀█ ▐█▐▐▌"
	@echo "▐███▌▐█▌▐▌▐█▄▄▌▐█ ▪▐▌██▐█▌"
	@echo "·▀▀▀ .▀▀▀  ▀▀▀  ▀  ▀ ▀▀ █▪"
	@echo "$(RESET)"

fclean: clean
	@echo "$(RED)=== Suppression de l'exécutable... ==="
	rm -f $(NAME)
	make --no-print-directory -C $(LIBFT_DIR) -s -j fclean
	make --no-print-directory -C $(MLX_DIR) -s -j fclean
	@echo "$(RED)"
	@echo "░       ░░░░      ░░░  ░░░░░░░░        ░░░      ░░░   ░░░  ░"
	@echo "▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒"
	@echo "▓      ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓"
	@echo "█  ████████  ████  ██  ████████  ████████        ██  ██    █"
	@echo "█  █████████      ███       ███       ███  ████  ██  ███   █"
	@echo "$(RESET)"

re: fclean all
	@echo "$(GREEN)=== Réinitialisation terminée ==="
	@echo "░▒▓███████▓▒░░▒▓████████▓▒░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓███████▓▒░░▒▓██████▓▒░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░" 
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░"
	@echo "$(RESET)"

.PHONY: all clean fclean re
