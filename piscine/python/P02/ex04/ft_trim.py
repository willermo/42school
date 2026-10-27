# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_trim.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:09:18 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 23:12:01 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def args_are_valid(args):
    if len(args) < 3:
        print("Error! You must insert at least 2 values")
        return False
    return True

def trim(lst):
    if len(lst) > 1:
        del lst[0]
        del lst[-1]

def main():
    if not args_are_valid(sys.argv):
        return
    lst = sys.argv[1:]
    trim(lst)
    print("The new list is:", lst)

if __name__ == "__main__":
    main()
