# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_print.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:55:47 by doriani           #+#    #+#              #
#    Updated: 2023/12/11 15:59:32 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

string = input("Insert a string: ")
n = int(input("Insert an integer: "))
if n >= len(string):
    print("Error: index out of range")
else:
    print(string[n], string[-n])
