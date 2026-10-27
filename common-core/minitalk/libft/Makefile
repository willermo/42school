# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:53:08 by doriani           #+#    #+#              #
#    Updated: 2023/04/16 13:53:25 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
SRC_FILES   = convert_char.c convert_decimal.c convert_hex.c convert_integer.c \
  convert_octal.c convert_percent.c convert_pointer.c convert_string.c         \
  convert_unsigned.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa_16.c ft_itoa_8.c              \
  ft_itoa_base.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c    \
  ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c    \
  ft_memset.c ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c       \
  ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c    \
  ft_strcpy.c ft_strdel.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c  \
  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strstr.c ft_strtrim.c   \
  ft_substr.c ft_swap.c ft_tolower.c ft_toupper.c ft_uitoa_base.c  ft_uitoa.c  \
  get_next_line.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#############
## Targets ##
#############
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

usage:
	@echo "Usage: make [usage | all | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Library build targets --"
	@echo "\tall: compile the library"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and library"
	@echo "\tre: fclean and all"
	