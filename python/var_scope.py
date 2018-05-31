#!/usr/bin/python

x=10

def foo():
	y=5
	bar = lambda y=y:x+y
	print bar()
	y=9
	print bar()


foo()
	
