#!/usr/bin/python
import sys

print "1st method:"
for i in range(0,10):
	sys.stdout.write('.')
	sys.stdout.flush()

print '\n2nd method:'
for i in range(0,10):
	print '.'
