#!/usr/bin/python

class instCnt(object):
	count = 0
	def __init__(self):
		instCnt.count+=1

	def __del__(self):
		instCnt.count-=1

	def howMany(self):
		return instCnt.count

a=instCnt()
print 'add a, count:',a.howMany()
b=instCnt()
print 'add b, count:',b.howMany()


del b
print 'del b, count:',a.howMany()

del a
print 'del a, count:',instCnt.count

		
