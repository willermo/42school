from new_student import Student
print("----- Testing Student class -----")
print("Test 1: student = Student(name=\"Edward\", surname=\"agle\")")
student = Student(name="Edward", surname="agle")
print(student)
print("Test 2: student = Student(name=\"Edward\", "
      "surname=\"agle\", login=\"eagle\")")
student = Student(name="Edward", surname="agle", login="eagle")
print(student)
print("Test 3: student = Student(name=\"Edward\", "
      "surname=\"agle\", id=\"eagle\")")
student = Student(name="Edward", surname="agle", id="eagle")
print(student)
print("Test 4: student = Student(name=1, surname=\"agle\", id=\"eagle\")")
student = Student(name=1, surname="agle", id="eagle")
print(student)
print("----- Testing Student.create() method -----")
print("Test 1: student = Student.create(name=\"Edward\", surname=\"agle\")")
student = Student.create(name="Edward", surname="agle")
print(student)
print("Test 2: student = Student.create(name=\"Edward\", surname=\"agle\", "
      "login=\"eagle\")")
student = Student.create(name="Edward", surname="agle", login="eagle")
print(student)
print("Test 3: student = Student.create(name=2, surname=\"agle\", "
      "id=\"eagle\")")
student = Student.create(name=2, surname="agle", id="eagle")
print(student)
