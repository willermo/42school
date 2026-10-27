# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    write_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:31 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 14:04:14 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def main():
    try:
        file_in = open("words.txt")
        file_out = open("long_words.txt", "w")
    except (FileNotFoundError, PermissionError, OSError):
        print("Error. Cannot open file")
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
    for line in long_lines:
        file_out.write(line)
        file_out.write("" if line[-1] == "\n" else "\n")
    file_out.close()
    print("The words longer than", word_length,"have been written on"
          , "\"long_words.txt\"")


if __name__ == "__main__":
    main()

