# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_summorial.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 13:51:18 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 17:27:44 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def ft_range(start, end):
    while start < end:
        yield start
        start += 1

def main():
    if len(sys.argv) != 2:
        print("Error! Usage: python3 ft_summorial.py <n>")
        return
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("n is not numeric")
        return

    if n < 0:
        print("Error! n must be >=0")
        return

    sum = 0
    for n in ft_range(0, n + 1):
        sum = sum + n
    print("The sum is:", sum)

if __name__ == "__main__":
    main()
