#!/usr/bin/python

class Parent(object):
	'Parent class...'
	def __init__(self):
		print "create an instance of ",self.__class__.__name__
	def parent_method(self):
		print "calling parent method"


class Child(Parent):
	'Child class...'
	def child_method(self):
		print "calling child method"


A_p = Parent()
A_p.parent_method()

print A_p.__doc__

B_c = Child()
B_c.child_method()

B_c.parent_method()

print B_c.__doc__
