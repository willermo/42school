# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sorted.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:08:55 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 20:31:48 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def args_are_valid(args):
    if len(args) < 3:
        print("Error! You must insert at least 2 numbers")
        return False, []
    try:
        lst = [int(arg) for arg in args[1:]]
    except ValueError:
        print("Error! Not numeric value found")
        return False, []
    return True, lst

def is_sorted(lst):
    return lst == sorted(lst, reverse=True)

def main():
    ret_val, lst = args_are_valid(sys.argv)
    if not ret_val:
        return
    if (is_sorted(lst)):
        print("The inserted sequence is sorted!")
    else:
        print("The inserted sequence is not sorted!")
        print("The correct order is", sorted(lst, reverse=True))


if __name__ == "__main__":
    main()
