# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/04/18 19:33:14 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= <name>
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
SRC_FILES   = <file1> <file2> ... <file n>
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBRARIES	= -L./libft -lft

#############
## Targets ##
#############
usage:
	@echo "Usage: make [usage | all | minitalk | <program 1> | <program 2> | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Minitalk build targets --"
	@echo "\tall: compiles client and server"
	@echo "\tminitalk: compiles client and server"
	@echo "\t<program 1>: compiles <program 1>"
	@echo "\t<program 2>: compiles <program 2>"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and programs"
	@echo "\tre: fclean and all"

all: $(NAME)

$(NAME):  $(LIBFT)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

<program 1>: $(OBJ_DIR)<file.o> $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)<file.o> -o <program 1>  $(INCLUDES) $(LIBRARIES)

<program 2>: $(OBJ_DIR)<file.o> $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)<file.o> -o <program 2>  $(INCLUDES) $(LIBRARIES)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	(cd $(LIBFT_DIR) && make clean)
	rm -f $(OBJS)

fclean: clean
	(cd $(LIBFT_DIR) && make fclean)
	rm -f server client

re: fclean all
