class StudentList:
    def _init_(self):
        self.students = []

    def add_student(self, name):
        self.students.append(name)
        print(f"Added student: {name}")

    def remove_student(self, name):
        if name in self.students:
            self.students.remove(name)
            print(f"Removed student: {name}")
        else:
            print(f"Student {name} not found.")

    def display_students(self):
        print("Current students:")
        for student in self.students:
            print(student)


# Example usage:
student_list = StudentList()
student_list.add_student("Huzaifa")
student_list.add_student("Arshad")
student_list.remove_student("Hamza")
student_list.display_students()
