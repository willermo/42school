# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_min.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:43:54 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 17:03:07 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def my_min(x = 0, y = 0, z = 0):
    
    min = x
    if y < min:
        min = y
    if z < min:
        min = z
    return min


def main():
    if len(sys.argv) != 4:
            print("Error! Usage: python3 ft_min.py <x> <y> <z>")
            return

    try:
        args = [float(arg) for arg in sys.argv[1:]]
    except ValueError:
        print("A value inserted is not numeric")
        return
    min = my_min(args[0], args[1], args[2])
    print("The min is:", min)

if __name__ == "__main__":
    main()
