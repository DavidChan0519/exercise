#!/usr/bin/python

def taxMe(cost, rate=0.05):
	print 'current rate:',rate
	return cost+cost*rate

val1=taxMe(100)
print "cost1:",val1

val2=taxMe(200,0.09)
print 'cost2:',val2


