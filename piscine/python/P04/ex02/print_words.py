# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:41 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 14:09:11 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def main():
    file_name = input("Insert file name: ")
    try:
        file_in = open(file_name)
    except (FileNotFoundError, PermissionError, OSError):
        print("Error! The specified file does not exist!")
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
    for line in file_in:
        if len(line) > word_length:
            long_lines.append(line)
    file_in.close()

    long_lines.sort()
    print("The words longer than", word_length,"are the following:")
    for line in long_lines:
        print(line[:-1] if line[-1] == "\n" else line)


if __name__ == "__main__":
    main()


