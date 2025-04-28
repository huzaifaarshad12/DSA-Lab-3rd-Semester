students = ["Huzaifa", "Arshad", "Hamza", "Talha", "Jamshaid"]

def search_student(name):
    if name in students:
        index = students.index(name)
        print(f"{name} found at index {index}.")
    else:
        print(f"{name} is not in the list.")

search_student("Huzaifa")
search_student("Jamshaid")
