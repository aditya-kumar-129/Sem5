# 1a

# n = int(input('Enter the number of elements you want to insert in the List:- '))
# l = []
# for i in range(n):
#   temp = int(input('Enter the element:- '))
#   l.append(temp)
# print(l)

# def removeDuplicates(l):
#   L =[]
#   for i in l:
#     if i not in L:
#       L.append(i)
#   print(L)

# l2 = [x for x in l if x%2==0]
# print('List of even numbers are:- ')
# print(l2)
# print('List of distinct numbers are:- ')
# removeDuplicates(l)
# print('Reverse of the inserted list is:- ')
# l.reverse()
# print(l)


# 1b

# file_name = input('Enter the file name:- ')
# fhand = open(file_name)
# dict={}   
# for line in fhand:
#   for word in line.split():
#     if word in dict:
#       dict[word] +=1
#     else:
#       dict[word] =1
# print(dict)

# 1c

def Max(l):
  if len(l)==1 :
    return l[0]
  else:
    return max(l[0],Max(l[1:]))

n = int(input('Enter the number of elements you want to insert in the List:- '))
l = []
for i in range(n):
  temp = int(input('Enter the element:- '))
  l.append(temp)
print(l)

print('The maximumm number present in the list is :- ',Max(l))
