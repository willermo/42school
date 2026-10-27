# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_ext_pos.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 16:55:45 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 20:34:10 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def ft_range(start, end):
    while start < end:
        yield start
        start += 1

def find_min(lst):
    min = lst[0]
    pos = 0
    for i in ft_range(1, len(lst)):
        if lst[i] < min:
            min = lst[i]
            pos = i
    return (min, pos)

def find_max(lst):
    max = lst[0]
    pos = 0
    for i in ft_range(1, len(lst)):
        if lst[i] > max:
            max = lst[i]
            pos = i
    return (max, pos)

def args_are_valid(args):
    if len(args) < 2:
        print("Error! Usage: python3 ft_ext_pos.py <x1> ... <xn>")
        return False, []
    try:
        lst = [int(arg) for arg in args[1:]]
    except ValueError:
        print("A value inserted is not numeric")
        return False, []
    return True, lst

def main():
    ret_val, lst = args_are_valid(sys.argv)
    if not ret_val:
        return
    min = find_min(lst)
    max = find_max(lst)
    print("The min is", min[0], "and its position is", min[1])
    print("The max is", max[0], "and its position is", max[1])

if __name__ == "__main__":
    main()
