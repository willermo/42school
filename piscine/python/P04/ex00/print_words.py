# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:22 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 14:05:57 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def main():
    try:
        file = open("words.txt")
    except FileNotFoundError:
        print("Error! File words.txt not found")
        return
    except PermissionError:
        print("Error! Cannot open the file words.txt")
        return
    
    word_length = -1
    while word_length < 1:
        try:
            word_length = int(input("Insert an integer: "))
            if word_length < 1:
                raise ValueError
        except ValueError:
            print("The number must be numeric and >= 0!")
            continue

    long_lines = []
    for line in file:
        if len(line) > word_length:
            long_lines.append(line)
    file.close()
    
    long_lines.sort()
    print("The words longer than", word_length,"are the following:")
    for line in long_lines:
        print(line[:-1] if line[-1] == "\n" else line)


if __name__ == "__main__":
    main()
