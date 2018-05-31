#!/usr/bin/python

def foo():
	print "foo"
	bar()

def bar():
	print "bar"


bar.__doc__='the doc str above'

foo()

help(bar)
