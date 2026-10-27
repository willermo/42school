# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sum_list.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:05:17 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 20:33:11 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def sum_list(lst = []):
    result = 0
    for n in lst:
         result = result + n
    return result


def main():
    lst = []
    while True:
        try:
            n = int(input("Insert integer: "))
        except ValueError:
            print("The number entered is not numeric")
        else:
            if n == 0:
                break
            lst.append(n)
    print("The sum is:", sum_list(lst))

if __name__ == "__main__":
    main()
    