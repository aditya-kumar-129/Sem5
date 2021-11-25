class Rectangle:
	def __init__(self):
		self.l=int(input("Enter length"))
		self.b=int(input("Enter breadth"))
	def area(self):
		area=self.l*self.b
		print("Area of rectangle:",area)

ob1=Rectangle()
ob1.area()
