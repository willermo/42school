# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:53:08 by doriani           #+#    #+#              #
#    Updated: 2023/03/07 18:36:19 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Variables ##
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -c
SRCS_DIR	= ./srcs/
SRC_FILES	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(SRCS_DIR), $(OBJ_FILES))


## Targets ##
all: $(SRCS) $(NAME)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(OBJS) $< -o $@ -I includes/

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -o $@ -c $< -I ./includes/

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
