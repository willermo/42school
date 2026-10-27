# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:53:08 by doriani           #+#    #+#              #
#    Updated: 2023/03/08 09:29:59 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Variables ##
NAME		= ft_cat
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= ./srcs/
SRC_FILES	= ft_cat.c ft_putchar.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(SRC_DIR), $(OBJ_FILES))


## Targets ##
all: $(SRC) $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(OBJ) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@  $<

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
