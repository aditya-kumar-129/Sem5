#print("Enter the number of elements")
r = int(input("Enter the number of elements"))
list = []
for x in range(0,r):
	list.append(int(input("enter the element ")));
print(list)

find = int(input("Enter the element to find"))
flag = 0

for x in list:
	if x == find:
		print("found element");
		flag = 1;
if flag==0:
	print("Element is not found!");
