#!/usr/bin/python

fp = open('test.txt')

for eachline in fp:
	#if str(eachline)[0] == '#':
	type(eachline)
	if eachline[0] == '#':
		continue
	print eachline
'''
filelength=[word for eachline in fp for word in eachline.split()] 

print "length:", len(filelength)

fp.close()

filename = raw_input("Please input file name :")

fp= open(filename,'r')
alllines=fp.readlines()

fp.close()

for eachline in alllines:
	print eachline
'''
