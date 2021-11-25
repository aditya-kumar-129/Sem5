import os
import sys
from functools import reduce

if(len(sys.argv)!=2):
	print('Argument length is less than 2')
	sys.exit()

if(not(os.path.exists(sys.argv[0]))):
	print('File path is not correct')
	sys.exit()

if(sys.argv[1].split('.')[-1]!='txt'):
	print('FIle format is not of txt type')
	sys.exit()

dic = {}

with open(sys.argv[1]) as file:
	for line in file:
		for word in line.split():
			dic[word] = dic.get(word,0)+1

print(dic)

#  By default, a Map in C++ is sorted in increasing order based on its key
sorted_dict = sorted(dic.items() , key = lambda x:x[1],reverse=True)
# (key:value)

wordlen = []
for i in range(10):
	try:
		wordPair = sorted_dict[i]
		wordlen.append(len(wordPair[0]))
		print(wordPair[0],'frequency:- ',wordPair[1],'Word Length :- ',len(wordPair[0]))

	except IndexError:
		print('File does not contain 10 words')
		break

print('Word length of 10 words are:- ')
print(wordlen)

sum =  reduce(lambda x,y:x+y ,wordlen)
print('average of the wordlength is :- ',sum/len(wordlen))

oddSquare = [x**2 for x in wordlen if x%2!=0]
print(oddSquare)