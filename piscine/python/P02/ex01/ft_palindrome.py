# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_palindrome.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:08:40 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 18:26:35 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def args_are_valid(args):
    if len(args) < 2:
        print("Error! No string inserted!")
        return False
    elif len(args) > 2:
        print("Error! Insert just 1 string!")
        return False
    return True

def space_removed_string(string):
    out_string = ""
    for char in string:
        if char != " ":
            out_string = out_string + char
    return out_string

def is_palindrome(string):
    i = 0
    j = -1
    string = space_removed_string(string)
    while i <= len(string) + j and string[i] == string[j]:
        i = i + 1
        j = j - 1
    if i >= len(string) + j:
        return True
    return False

def main():
    if not args_are_valid(sys.argv):
        return
    if is_palindrome(sys.argv[1]):
        print("The string", sys.argv[1], "is palindrome")
    else:
        print("The string", sys.argv[1], "is not palindrome")


if __name__ == "__main__":
    main()
