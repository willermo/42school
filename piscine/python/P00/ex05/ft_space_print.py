# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_space_print.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:11:58 by doriani           #+#    #+#              #
#    Updated: 2023/12/11 16:26:22 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

string = input("Insert a string: ")
if len(string) > 20:
    string = string[-20:]
spaces = 20 - len(string)
print(' ' * spaces + string)