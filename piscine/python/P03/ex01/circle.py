# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    circle.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:07 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 02:05:57 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Point:
    def __init__(self, coords):
        self.x, self.y = coords
    
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
        self.center = Point(args[0])
        self.radius = args[1]
    
    def __str__(self):
        return ("Circle of center " + str(self.center) 
              + " and radius " + str(self.radius))

def main():
    circle = Circle((150, 100), 75)
    print(circle)

if __name__ == "__main__":
    main()
