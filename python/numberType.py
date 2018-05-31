#!/usr/bin/python

def displayNumType(num):
	print num,'is'
	if isinstance(num, (int , long, float, complex)):
		print "a number of type:",type(num).__name__
	else:
		print 'not a number at all!'

displayNumType(1)
displayNumType(2.3)
displayNumType(4+5j)

displayNumType("abc")
