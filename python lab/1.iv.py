#print("Enter the number of elements")
r = int(input("Enter the number of elements"))
list = []
for x in range(0,r):
	list.append(int(input("enter the element ")));
print(list)

rem = int(input("Enter the element to remove"))

list.remove(rem)

print(list)
