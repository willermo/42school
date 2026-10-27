# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    circle.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:12 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 02:46:35 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y
    
    def distance(self, other):
        dx = other.x - self.x
        dy = other.y - self.y
        distance = ((dx ** 2) + (dy ** 2)) ** 0.5
        return distance
    
    def __str__(self):
        return str((self.x, self.y))

def ft_range(start, end):
    while start < end:
        yield start
        start += 1

class Circle:
    def __init__(self, *args):
        self.center = Point(args[0][0], args[0][1])
        self.radius = args[1]
    
    def __str__(self):
        return ("Circle of center " + str(self.center) 
              + " and radius " + str(self.radius))
    
    def contains(self, point):
        return True if self.center.distance(point) <= self.radius else False

def args_are_valid(args):
    if len(args) != 3:
        print("Error! Usage: python3 circle.py <point_x> <point_y>")
        return False
    return True

def main():
    if not args_are_valid(sys.argv):
        return
    circle = Circle((0, 0), 1)
    try:
        point = Point(float(sys.argv[1]), float(sys.argv[2]))
    except:
        print("Parse error")
        return
    interpolate_string = "in" if circle.contains(point) else "out of"
    print("The Point " + str(point) + " lies " + interpolate_string
                + " the Circle of center " + str(circle.center)
                + " and radius " + str(circle.radius))

if __name__ == "__main__":
    main()
