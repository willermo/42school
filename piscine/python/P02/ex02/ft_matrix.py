# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_matrix.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:08:46 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 01:17:17 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def args_are_valid(args):
    if len(args) != 3:
        print("Error! Usage: python3 ft_matrix.py <n> <m>")
        return False
    return True

def ft_map(function, iterable):
    for i in iterable:
        yield function(i)

def print_matrix(matrix, rows):
    print("The inserted matrix is:")
    for row in range(0, rows):
        print(matrix[row])

def print_sum_over_rows(matrix, rows, cols):
    sum = [0 for val in range(rows)]
    for cols_idx in range(0, cols):
        for rows_idx in range(0, rows):
            sum[rows_idx] = sum[rows_idx] + matrix[rows_idx][cols_idx]
    print("The sum over rows is:")
    print(sum)

def print_sum_over_columns(matrix, rows, cols):
    sum = [0 for val in range(cols)]
    for rows_idx in range(0, rows):
        for cols_idx in range(0, cols):
            sum[cols_idx] = sum[cols_idx] + matrix[rows_idx][cols_idx]
    print("The sum over columns is:")
    print(sum)

def get_input_string(rows_idx, cols_idx):
    input_string = "Insert the element in position "
    input_string = input_string + "(" 
    input_string = input_string + str(rows_idx) + ", " + str(cols_idx)
    input_string = input_string  + "): "
    return input_string

def main():
    if not args_are_valid(sys.argv):
        return
    
    try:
        rows, cols = ft_map(int, sys.argv[1:])
    except ValueError:
        print("Error! One or both of the given dimensions is not numeric!")
        return
    
    cols_idx, rows_idx = 0, 0
    matrix = [[0 for val in range(cols)] for val in range(rows)]
    while rows_idx < rows:
        cols_idx = 0
        while cols_idx < cols:
            input_string = get_input_string(rows_idx, cols_idx)
            try:
                matrix[rows_idx][cols_idx] = float(input(input_string))
            except ValueError:
                print("This is not a valid number!")
            else:
                cols_idx = cols_idx + 1
        rows_idx = rows_idx +1
    print_matrix(matrix, rows)
    print_sum_over_rows(matrix, rows, cols)
    print_sum_over_columns(matrix, rows, cols)

if __name__ == "__main__":
    main()
