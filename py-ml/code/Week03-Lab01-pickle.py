import pickle


class Student():
    def __init__(self, n, age):
        self.name = n
        self.age = age

    def introduceSelf(self):
        # print("My name is "+ str(self.name) + ". I'm "+str(self.age)+" years old." )
        print("My name is {}. I'm {} years old.".format(self.name, self.age))


if __name__ == '__main__':
    student_1 = Student("Jessica", 20)
    filename = "Test.pickle"
    pickle.dump(student_1, open(filename, 'wb'))
    with open(filename, 'rb') as f:
        student_from_file = pickle.load(f)
    print(student_from_file)
    student_from_file.introduceSelf()
