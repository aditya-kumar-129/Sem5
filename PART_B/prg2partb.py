def celciusToKelvin(a):
  return a+273.15
def kelvinToCelcius(a):
  return a-273.15

def celciusToFarenheit(a):
  return a*(9/5)+32
def farenheitToCelcius(a):
  return (a-32)*(5/9)

def farenheitToKelvin(a):
  return celciusToKelvin(farenheitToCelcius(a))
def kelvinToFarenheit(a):
  return celciusToFarenheit(kelvinToCelcius(a))

op1=[]
op2=[]
op3=[]
op4=[]
op5=[]
op6=[]

select='y'

while(select=='y'):
  print('Enter the corresponding number to perform the corresponding operation:- ')
  choice = int(input('1.C->F  2.F->C  3.C->K  4.K->C  5.F->K  6.K->F \n'))
  if(choice>0 and choice<=6):
    if(choice==1):
      temp = float(input('Enter the temperature in celcius:- '))
      op1 = op1 + [(temp,celciusToFarenheit(temp))]
      print('Celcius to Farenheit:- ')
      print(sorted(op1))
    elif(choice==2):
      temp = float(input("Enter the temperature in farenhiet: "))
      op2 = op2 + [(temp, farenheitToCelcius(temp))]
      print("Farenhiet to Celsius\n")
      print(sorted(op2))
    elif(choice == 3):
      temp = float(input("Enter the temperature in celsius: "))
      op3 = op3 + [(temp, celciusToKelvin(temp))]
      print("Celsius to Kelvin\n")
      print(sorted(op3))
    elif(choice == 4):
      temp = float(input("Enter the temperature in kelvin: "))
      op4 = op4+[(temp, kelvinToCelcius(temp))]
      print("Kelvin to Celsius\n")
      print(sorted(op4))
    elif(choice == 5):
      temp = float(input("Enter the temperature in farenhiet: "))
      op5 = op5+[(temp, farenheitToKelvin(temp))]
      print("Farenhiet to Kelvin\n")
      print(sorted(op5))
    elif(choice == 6):
      temp = float(input("Enter the temperature in kelvin: "))
      op6 = op6+[(temp, kelvinToFarenheit(temp))]
      print("Kelvin to Farenhiet\n")
      print(sorted(op6))
  else:
    print("Invalid Input")
  select = input("Enter Y to continue and N to terminate\n").lower()