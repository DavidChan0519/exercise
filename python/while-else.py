#!/usr/bin/python

def showMaxFactor(num):
	count = num / 2
	while count > 1:
		if num % count == 0:
			print "the largest factor of %d is %d" %(num, count)
			break
		count-=1
	else :
		print num, "is prime"


for eachNum in range(10,20):
	showMaxFactor(eachNum)
	
