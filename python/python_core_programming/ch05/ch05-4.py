def isRyear(years):
	if (years % 4) == 0 and (years % 100) !=0 :
		print "%d is R year"%years
	elif (years % 400) == 0 :
		print "%d is R year"%years
	else:
		print "%d is not R year"%years

isRyear(int(raw_input("Please input year:")))