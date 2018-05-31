#!/usr/bin/python

def tupleVar(arg1, arg2='default',*theRest):
	print 'arg1:',arg1
	print 'arg2:',arg2
	
	for eachone in theRest:
		print 'argc:',eachone


tupleVar('abc')
tupleVar(1,'2',3,4,5)
tupleVar(2,34,80,'hello')
	
