# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dump_word_dict.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:47 by doriani           #+#    #+#              #
#    Updated: 2023/12/14 16:45:23 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pickle

def main():
    try:
        file_in = open("words.txt")
    except (FileNotFoundError, PermissionError, OSError):
        print("Error. Cannot open file")
        return
    
    dictionary = {}
    for line in file_in:
        line = line[:-1] if line[-1] == "\n" else line
        dictionary[len(line)] = dictionary.get(len(line), 0) + 1
    file_in.close()
    with open("word_count.pickle", "wb") as file_out:
        pickle.dump(dictionary, file_out)

if __name__ == "__main__":
    main()
