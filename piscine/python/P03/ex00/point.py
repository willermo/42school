# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    point.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:01 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 01:30:40 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Point:
    def __init__(self, *args):
        self.x, self.y = args[:2]
    
    def distance(self, other):
        dx = other.x - self.x
        dy = other.y - self.y
        distance = ((dx ** 2) + (dy ** 2)) ** 0.5
        return distance

def ft_range(start, end):
    while start < end:
        yield start
        start += 1

def get_point(coords_string):
    separator_idx = -1
    i = 0
    for char in coords_string:
        if char == ",":
            if separator_idx == -1:
                separator_idx = i
            else:
                raise LookupError
        i += 1
    if separator_idx == -1:
        raise LookupError
    return Point(float(coords_string[:separator_idx]), 
                 float(coords_string[separator_idx + 1:]))

def main():
    ret_val = False
    try:
        p1 = get_point(input("Insert the coordinates of the first point: "))
        p2 = get_point(input("Insert the coordinates of the second point: "))
    except LookupError:
        print("Error! Coordinates must be separated by 1 comma")
        return
    except ValueError:
        print("Error! One or both coordinates are not numeric")
        return
    print("Their distance is:", p1.distance(p2))

if __name__ == "__main__":
    main()
