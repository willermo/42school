# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_compare.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 09:55:08 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 00:18:37 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 ft_compare.py <arg1> <arg2>")
        return
        
    try:
        args = [float(arg) for arg in sys.argv[1:]]
    except ValueError:
        print("A value inserted is not numeric")
        return
    first, second = args[0:]
    if first > second:
        print(first, "is greater than", second)
    elif first == second:
        print(first, "is equal to", second)
    else:
        print(first, "is less than", second)

if __name__ == "__main__":
    main()
