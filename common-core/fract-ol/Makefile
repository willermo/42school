# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/06/09 20:07:00 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= fract_ol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
RM			= rm -f
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
## Base sources section ##
SRC_FILES   = fract_ol fract_ol_utils fract_ol_init fract_ol_validators        \
fract_ol_actions_move fract_ol_actions_zoom  hooks mandelbrot julia burning_ship
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
## MLX utils sources section ##
MLXUTILS_FILES= mlx_utils mlx_helpers
MLXUTILS_DIR	= ./src/mlx_utils/
MLXUTILS_OBJ_DIR= ./obj/mlx_utils/
## Colors sources section ##
COLORS_FILES= colors_hsv_1 colors_rgb_1 colors_rgb_2 colors_rgb_3              \
colors_hsv_to_rgb_1 colors_hsv_to_rgb_2
COLORS_DIR	= ./src/colors/
COLORS_OBJ_DIR= ./obj/colors/
SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))           \
$(addsuffix .c, $(addprefix $(COLORS_DIR), $(COLORS_FILES)))                   \
$(addsuffix .c, $(addprefix $(MLXUTILS_DIR), $(MLXUTILS_FILES)))
OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC_FILES)))           \
$(addsuffix .o, $(addprefix $(COLORS_OBJ_DIR), $(COLORS_FILES)))               \
$(addsuffix .o, $(addprefix $(MLXUTILS_OBJ_DIR), $(MLXUTILS_FILES)))
LIBRARIES	= -L./libft -L./libmlx -lft -lmlx -lm -lXext -lX11

#############
## Targets ##
#############
usage:
	@echo "Usage: make [usage | all | fract_ol | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Fract_ol build targets --"
	@echo "\tall: compiles client and server"
	@echo "\tfract_ol: compiles fract_ol program"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and programs"
	@echo "\tre: fclean and all"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBRARIES)

$(OBJS): $(SRCS)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLXUTILS_OBJ_DIR)%o: $(MLXUTILS_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(COLORS_OBJ_DIR)%o: $(COLORS_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	(cd $(LIBFT_DIR) && make clean)
	$(RM) $(OBJS)

fclean: clean
	(cd $(LIBFT_DIR) && make fclean)
	$(RM) fract_ol

re: fclean all

PHONY: all clean fclean re fract_ol
