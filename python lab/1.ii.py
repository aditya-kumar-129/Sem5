#print("Enter the number of elements")
r = int(input("Enter the number of elements"))
list = []
for x in range(0,r):
	list.append(int(input("enter the element ")));
print(list)

mini = list[0]
maxi = list[0]

for x in list:
	mini = min(x,mini);
	maxi = max(x,maxi);
print("minimum is ",mini , "\nmaximum is ",maxi);

	
