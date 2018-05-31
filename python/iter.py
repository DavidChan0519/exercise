#!/usr/bin/python

aList=['a','b',123,]

fetch = iter(aList)


def do_something(i):
	print "val :", i


while True:
	try:
		i=fetch.next()
	except StopIteration:
		break

	do_something(i)



