# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2024/03/22 10:36:08 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= span
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -I./includes/
RM			= rm -f
## Base sources section ##
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
SOURCES   = $(patsubst %.cpp,%,$(notdir $(wildcard $(SRC_DIR)*.cpp)))
SRCS		= $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(SOURCES)))
OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SOURCES)))
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
	@echo "\$(NAME): compiles $(NAME)"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and program"
	@echo "\tre: combines fclean and all"

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(DEBUG)

$(OBJ_DIR)%o: $(SRC_DIR)%cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(LIBRARIES) $(DEBUG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re $(NAME)