#!/usr/bin/python

def fac_func(n):
	if n==0 or n==1:
		return 1
	print '%d *'%n
	return fac_func(n-1)*n



val = fac_func(3)
print "result:",val
