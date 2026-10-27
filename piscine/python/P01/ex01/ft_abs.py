# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_abs.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 10:51:23 by doriani           #+#    #+#              #
#    Updated: 2023/12/12 17:00:04 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def evaluate(res):
    try :
        res = eval(input("Insert an expression: "))
    except (SyntaxError, NameError):
        print ("Malformed expression")
        return -1
    else:
        return res if  res >= 0 else res * -1


def main():
    result = -1
    while result < 0:
        result = evaluate(result)
    print("The result is:", result)

if __name__ == "__main__":
    main()