#!/usr/bin/python

fname=raw_input("Enter file name:")
print fname

try:
	fobj=open(fname,'r')
except IOError,e:
	print "*** file open error ***",e
else:
	for eachline in fobj:
		print eachline
	fobj.close()