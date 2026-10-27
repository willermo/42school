# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_max.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:29:59 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 17:00:46 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys



def main():
    if len(sys.argv) != 4:
        print("Error! Usage: python3 ft_max.py <x> <y> <z>")
        return

    try:
        args = [float(arg) for arg in sys.argv[1:]]
    except ValueError:
        print("A value inserted is not numeric")
        return
    max, second, third = args[0:]
    if second > max:
        max = second
    if third > max:
        max = third
    print("The max is:", max)

if __name__ == "__main__":
    main()