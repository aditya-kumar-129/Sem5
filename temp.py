# 1 a
# # Read a list of number
# n = int(input('Enter the number of elements present on the list:- '))
# l = []
# for i in range(n):
#   temp = int(input('Enter the number:- '))
#   l.append(temp)
# print('the entered numbers are:- ')
# print(l)

# function to remove the duplicate number present in the list
# L = []
# def duplicates():
#   for i in l:
#     if i not in L:
#       L.append(i)

# print('Distinct element present in the list are:- ')
# duplicates()
# print(L)

# even_number = [x for x in l if x % 2 == 0]
# print('the Even number present in the list is:- ')
# print(even_number)

# print('reversed list is:- ')
# l.reverse()
# print(l)

# 1b

# frequency = {}
# file_name = input('Enter the file name:- ')
# fhand = open(file_name)
# for line in fhand:
#   for word in line.split():
#     if word in frequency:
#       frequency[word] +=1
#     else:
#       frequency[word] = 1
# print(frequency)

# 1c

# recursive function to find the maximum of the number present in the list

# def maximu(l):
#   if len(l) == 1:
#     return l[0]
#   else:
#     return max(l[0],maximu(l[1:]))

# print(maximu(l))

# 2

# def celciustokelvin(c):
#   return c+ 273.15
# def kelvintocelcius(k):
#   return k - 273.15

# def celciustofarenheight(c):
#   return c*(9/5) + 32
# def farenheighttocelcius(f):
#   return (f-32)*(5/9)

# def kelvintofarenheight(k):
#   return celciustofarenheight(kelvintocelcius(k))
# def farenheighttokelvin(f):
#   return farenheighttocelcius(celciustokelvin(f))

# op1 =[]
# op2 =[]
# op3 =[]
# op4 =[]
# op5 =[]
# op6 =[]

# select = 'y'

# while(select == 'y'):
#   print('1.) C->K  2.)K->C  3.)C->F  4.)F->C  5.)K->F  6.)F->K')
#   choice = int(input('Enter the number corresponding to the operation that you want to perform:-'))
#   if choice<=6 and choice>=1 :
#     if choice == 1:
#       celcius = float(input('Enter the temperature in celcius:- '))
#       op1 = op1 + [(celcius , celciustokelvin(celcius))]
#       print('celcius to kelvin:- ')
#       print(sorted(op1))
#     elif choice == 2:
#       kelvin = float(input('Enter the temperature in kelvin:- '))
#       op2 = op2 + [(kelvin, kelvintocelcius(kelvin))]
#       print('kelin to celcius:- ')
#       print(sorted(op2))
#     elif choice == 3:
#       celcius = float(input('Enter the temperature in celcius:- '))
#       op3 = op3 + [(celcius, celciustofarenheight(celcius))]
#       print('celcius to farenheight:- ')
#       print(sorted(op3))
#     elif choice == 4:
#       farenheight = float(input('Enter the temperature in farenheight:- '))
#       op4 = op4 + [(farenheight, farenheighttocelcius(farenheight))]
#       print('farenheight to celcius:- ')
#       print(sorted(op4))
#     elif choice == 5:
#       kelvin = float(input('Enter the temperature in kelvin:- '))
#       op2 = op2 + [(kelvin, kelvintofarenheight(kelvin))]
#       print('kelin to farenheight:- ')
#       print(sorted(op2))
#     elif choice == 6:
#       kelvin = float(input('Enter the temperature in kelvin:- '))
#       op2 = op2 + [(kelvin, farenheighttokelvin(kelvin))]
#       print('kelin to celcius:- ')
#       print(sorted(op2))
#   else:
#     print('You have entered wrong choice:- ')
#     select = input('Enter Y for continue and N for terminate:- ').lower()

# class sentenceReverser:
#   vowels = ['a','e','i','o','u','A','E','I','O','U']
#   reversed_string = ""
#   vowelCount = 0
#   sentence = ""
#   def __init__(self,sentence):
#     self.sentence = sentence
#     self.reverser()
#   def reverser(self):
#     self.reversed_string = " ".join(reversed(self.sentence.split(' ')))
#     return self.reversed_string
#   def getVowelCount(self):
#     self.vowelCount=0
#     for i in self.sentence:
#       if i in self.vowels:
#         self.vowelCount +=1
#     return self.vowelCount

# inp = []

# for i in range(2):
#   temp = input('ENter the String:- ')
#   ob = sentenceReverser(temp)
#   inp.append(ob)

# sorted_item = sorted(inp,key= lambda x:x.getVowelCount(),reverse = True)

# for i in range(len(sorted_item)):
#   print('Reversed String :- ',sorted_item[i].reverser(), 'Vowel Count:- ',sorted_item[i].getVowelCount())


# 5

# import os
# import sys
# from functools import reduce

# if(len(sys.argv) != 2):
#   print('Argument length is Less than 2')
#   sys.exit()

# if(not(os.path.exists(sys.argv[0]))):
#   print('File path is worng')
#   sys.exit()

# if(sys.argv[1].split('.')[-1] != 'txt'):
#   print('File type is not of txt format')
#   sys.exit()

# dic = {}

# fname = open(sys.argv[1])
# for line in fname:
#   for word in line.split():
#     if word in dic:
#       dic[word] += 1
#     else:
#       dic[word] = 1

# print(dic)


# sorted_dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)
# print(sorted_dic)
# word_len = []

# for i in range(10):
#   try:
#     wordPair = sorted_dic[i]
#     word_len.append(len(wordPair[0]))
#     print('frequency of', wordPair[0], 'is ', wordPair[1],' Length of Word is :- ', len(wordPair[0]))

#   except IndexError:
#     print('Not have 10 words')
#     break

# print('Word length of 10 words are:- ')
# print(word_len)

# # finding the average
# sum = reduce(lambda x,y:x+y,word_len)
# print('Average of all the word length is ',sum/len(word_len))


# oddquare =[x**2 for x in word_len if x%2!=0]
# print(oddquare)