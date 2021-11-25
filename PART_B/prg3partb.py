class sentenceReverser:
  vowels = ['a','e','i','o','u']
  vowelCount =0
  sentence=""
  reversed_string = ""
  def __init__(self,sentence):
    self.sentence = sentence
    self.reverser()
  def reverser(self):
    self.reversed_string = " ".join(reversed(self.sentence.split()))
    return self.reversed_string
  def getVowelCount(self):
    self.vowelCount = 0
    for i in self.sentence:
      if i.lower() in self.vowels:
        self.vowelCount += 1
    return self.vowelCount

inp = []

for i in range(2):    
  temp = input("Enter string:- ") 
  ob = sentenceReverser(temp)
  inp.append(ob)

sorted_item = sorted(inp,key = lambda x:x.getVowelCount(),reverse=True)

for i in range (len(sorted_item)):
  print('Reversed String: ',sorted_item[i].reverser(),'Vowel count: ',sorted_item[i].getVowelCount())
