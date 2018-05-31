#!/usr/bin/python

def foo():
	print 'calling foo...'
	aString='abc'
	anInt = 42
	print 'foo() global :',globals().keys()
	print 'foo() local :',locals().keys()

print '__main__ global:',globals().keys()
print '__main__ local:',locals().keys()

foo()
