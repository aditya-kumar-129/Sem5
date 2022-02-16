def AtomicDictionary():
	diction={
		"Carbon":"C",
		"Potassium":"K",
		"Oxygen":"O"
	}

	print("Dictionary",diction)
	
	c=input("Enter the element")
	d=input("Enter the symbol of corresponding element")
	diction[c]=d
	print("New Dictionary",diction)
	print("Number of elements in Dictionary:",len(diction))

	search=input("Enter the element u want to search for:")
	if search in diction:
		print("Element found")
	else:
		print("Element not found")

AtomicDictionary()	
