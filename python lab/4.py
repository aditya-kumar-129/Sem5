temp = input("Input the  temperature you like to convert in preferable scale : ")
degree = int(temp[:-1])
i_convention = temp[-1]

def farenheit(x):
    return int(round((9 * x) / 5 + 32))

def celsius(y):
    return  int(round((y- 32) * 5 / 9))   

if i_convention.upper() == "C":
  result = farenheit(degree)
  o_convention = "Fahrenheit"
elif i_convention.upper() == "F":
  result = celsius(degree)
  o_convention = "Celsius"
else:
  print("Input proper convention.")
  quit()
print("The temperature in", o_convention, "is", result, "degrees.")
