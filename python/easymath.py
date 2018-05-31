#!/usr/bin/python

from operator import add,sub,mul,div
from random import randint,choice

ops= {'+':add, '-':sub ,'*':mul,'/':div}
MAXTRIES = 2


def doprob():
	op=choice('+-*/')
	nums=[randint(1,10) for i in range(2)]
	result=ops[op](*nums)
	pr='%d %s %d =' %(nums[0],op,nums[1])
	oops=0
	
    	while True:
		try:
            		if int(raw_input(pr)) == result:
                		print 'correct'
                		break
            		if oops == MAXTRIES:
                		print 'sorry... the answer is\n%s%d' % (pr, result)
            		else:
                		print 'incorrect... try again'
                		oops += 1
        	except (KeyboardInterrupt,
                	EOFError, ValueError):
            		print 'invalid input... try again'


def main():
	while True:
		doprob()
		try:
			opt=raw_input('Again? [y]').lower()
			if opt and opt[0] == 'n':
				break
		except (KeyboardInterrupt, EOFError):
			break


if __name__ == '__main__':
	main()				
