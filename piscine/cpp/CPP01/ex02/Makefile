# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/11/28 21:18:05 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= brain
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -I./includes/
RM			= rm -f
## Base sources section ##
SRC_FILES   = main
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
SRCS		= $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC_FILES)))
LIBRARIES	= 
DEBUG		= -g

#############
## Targets ##
#############
usage:
	@echo "Usage: make [usage | all | $(NAME) | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- $(NAME) build targets --"
	@echo "\tall: compiles  $(NAME)"
	@echo "\t$(NAME): compiles $(NAME)"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and program"
	@echo "\tre: fclean and all"

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(DEBUG)

$(OBJS): $(SRCS)

$(OBJ_DIR)%o: $(SRC_DIR)%cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(LIBRARIES) $(DEBUG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re $(NAME)
