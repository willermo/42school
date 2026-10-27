# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/04/16 20:18:28 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= minitalk
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
SRC_FILES   = server.c client.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBRARIES	= -L./libft -lft

#############
## Targets ##
#############
all: $(NAME)

$(NAME): server client $(LIBFT)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

server: $(OBJ_DIR)server.o $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)server.o -o server  $(INCLUDES) $(LIBRARIES)

client: $(OBJ_DIR)client.o $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_DIR)client.o -o client  $(INCLUDES) $(LIBRARIES)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	(cd $(LIBFT_DIR) && make clean)
	rm -f $(OBJS)

fclean: clean
	(cd $(LIBFT_DIR) && make fclean)
	rm -f server client

re: fclean all

usage:
	@echo "Usage: make [usage | all | minitalk | server | client | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Minitalk build targets --"
	@echo "\tall: compiles client and server"
	@echo "\tminitalk: compiles client and server"
	@echo "\tserver: compiles server"
	@echo "\tclient: compiles client"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and programs"
	@echo "\tre: fclean and all"