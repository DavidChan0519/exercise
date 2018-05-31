#!/usr/bin/python

import os

while True:
	fname=raw_input("Enter file name:")
	if os.path.exists(fname):
		print "%s already exists"%fname
	else:
		break

all=[]
print "\nEnter lines ('.' by itself to quit).\n"

while True:
	entry=raw_input('>')
	if entry =='.':
		break
	else:
		all.append(entry)

fobj=open(fname,'w')
fobj.write('\n'.join(all))
fobj.close()


print 'Done'
