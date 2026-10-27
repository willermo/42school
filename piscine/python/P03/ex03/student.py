# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    student.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:11:17 by doriani           #+#    #+#              #
#    Updated: 2023/12/13 03:16:24 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Person:
    def __init__(self, first_name, last_name):
        self.first_name, self.last_name = first_name, last_name
    def __str__(self):
        return self.first_name + " " + self.last_name

class Student(Person):
    def __init__(self, first_name, last_name, course = ""):
        super().__init__(first_name, last_name)
        self.course = course
    def __str__(self):
        if self.course == "":
            return super().__str__() + " is not registered to any course"
        else:
            return super().__str__() + " is registered to " + self.course

def main():
    first_name = ""
    while first_name == "":
        first_name = input("Insert first name: ")
    last_name = ""
    while last_name == "":
        last_name = input("Insert last name: ")
    student_answer = input("Are you a student? (y/n)")
    while student_answer != "y" and student_answer != "n":
        student_answer = input("Please type \"y\" or \"n\": ")
    is_student = True if student_answer == "y" else False
    if is_student:
        course = input("Please insert your degree course: ")
        user = Student(first_name, last_name, course)
    else:
        user = Person(first_name, last_name)
    print(user)

if __name__ == "__main__":
    main()
