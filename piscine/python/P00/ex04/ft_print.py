# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_print.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:00:16 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 15:03:39 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

string = input("Insert a string: ")
n = None
while n == None:
    try:
        n = int(input("Insert an integer: "))
    except ValueError:
        print("Input is not a number.")
        n = None

if (n >= 0 and n >= len(string)) or (n < 0 and -n > len(string)):
    print("Error: index out of range")
else:
    if n > 0:
        print(string[n:-n + len(string) + 1])
    else:
        print(string[n:-n])
