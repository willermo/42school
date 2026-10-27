# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_char_count.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:09:25 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 14:26:33 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys


def args_are_valid(args):
    if len(args) == 1:
        print("Error! No string given")
        return False
    elif len(args) > 2:
        print("Error! Too many args")
        return False
    return True

def main():
    if not args_are_valid(sys.argv):
        return
    string = sys.argv[1].lower()
    chars = {}
    for char in string:
        chars[char] = chars.get(char, 0) + 1
    
    chars_keys = list(chars.keys())
    chars_keys.sort()
    sorted_chars = {i: chars[i] for i in chars_keys}
    print("Char count:")
    for char in sorted_chars:
        print(char, "=", sorted_chars[char])

if __name__ == "__main__":
    main()
