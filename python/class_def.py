#!/usr/bin/python

class Myclass:
	def __init__(self, nm, ph):
		self.name= nm
		self.phone=ph
		print "created instance for :",self.name
	def update(self,newph):
		self.phone=newph
		print "updated phone #%d for %s:"%(self.phone,self.name)


David=Myclass('David',18682750756)
John =Myclass('John',18000000000)

David.update(123)
	
