# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/06/06 09:52:29 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= push_swap
BONUS_NAME	= checker
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
RM			= rm -f
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
SRC_FILES   = push_swap_helpers push_swap_utils push_swap_validators \
push_swap_moves_swap push_swap_moves_push push_swap_moves_reverse_rotate       \
push_swap_moves_rotate push_swap_sort push_swap_sort_helpers                   \
push_swap_sequences_1 push_swap_sequences_2 
OBJ_FILES	= $(SRC_FILES:.c=.o)
M_OBJ_FILES = $(NAME:.c=.o)
B_SRC_FILES = checker checker_utils 
B_OBJ_FILES = $(B_SRC_FILES:.c=.o)
SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))
M_SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(NAME))) 
B_SRCS      = $(addsuffix .c, $(addprefix $(SRC_DIR), $(B_SRC_FILES)))
OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(OBJ_FILES)))
M_OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(M_OBJ_FILES)))
B_OBJS      = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(B_OBJ_FILES)))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBRARIES	= -L./libft -lft

#############
## Targets ##
#############
usage:
	@echo "Usage: make [usage | all | push_swap | bonus |clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- push_swap build targets --"
	@echo "\tall: compiles push_swap program"
	@echo "\tpush_swap: compiles push_swap program"
	@echo "\tbonus: compiles checker program"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and programs"
	@echo "\tre: fclean and all"

all: $(NAME)

$(NAME):  $(LIBFT) $(OBJS) $(M_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(M_OBJS) -o $(NAME) $(INCLUDES) $(LIBRARIES)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BONUS_NAME): $(LIBFT) $(B_OBJS) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) -o $(BONUS_NAME) $(INCLUDES) $(LIBRARIES)

bonus: $(BONUS_NAME)

clean:
	(cd $(LIBFT_DIR) && make clean)
	$(RM) $(OBJS) $(M_OBJS) $(B_OBJS)

fclean: 
	(cd $(LIBFT_DIR) && make fclean)
	$(RM) $(OBJS) $(M_OBJS) $(NAME) $(B_OBJS) $(BONUS_NAME)

re: fclean all
