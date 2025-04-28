"""Mutltiline comments
if 5 > 2:
            print("Five is greater than two!")
if 5 <2:
            #print("Five is greater than two")
            print("Five is greater than two")
"""
"""
x= 5
y="Hello World"# huzaifa arshad is very sincere boy. Single line comments
print(x)
print(y)

x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0
print(x)
print(y)
print(z)

x= 5
y= "Huzaifa Arshad"
print (type(x))
print (type(y))

x, y, z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)

x = y = z = "Orange"
print(x)
print(y)
print(z)

x = "Python "
y = "is "
z = "awesome"
print(x + y + z)

x = "Python"
y = "is"
z = "awesome"
print(x, y, z)

x = 5
y = "John"
print(x, y)


x = "awesome"

def myfunc():
  print("Python is " + x)
myfunc()



x = "awesome"

def myfunc():
  x = "fantastic"
  print("Python is " + x)

myfunc()

print("Python is " + x)

#List
x = ["apple", "banana", "cherry"]
print(x)


a = input ("Enter the value:") #a is string
#conversion of string to int data type
b= int(a)
print ("Entered value is:" + str(b))
#9We need to convert int type variable to string. Because in python concatenation of 
#int and string type variables is not possible without conversion.



def SearchArr(Arr, x):
    return [i for i in range(len(Arr)) if Arr[i] == x]

# Example usage:
Arr = [22, 2, 1, 7, 11, 13, 5, 2, 9]
x = 2
indices = SearchArr(Arr, x)
print(f"Index: {','.join(map(str, indices))}")

"""

def SearchA(Arr, x):
    return [i for i, val in enumerate(Arr) if val == x]

# Example usage:
X = [22, 2, 1, 7, 11, 13, 5, 2, 9]
x = int(input("Enter the number: "))
indices = SearchA(X, x)
print(f"Index: {','.join(map(str, indices))}")

"""



"""
