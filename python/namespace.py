#!/usr/bin/python

def foo():
	pass

foo.__doc__='oops, forgot to add str above'
foo.version=1.0

print 'doc:', foo.__doc__
print 'version:', foo.version
