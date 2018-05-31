#!/usr/bin/python

def testit(func, *nkwargs, **kwargs):
	try:
		retval = func(*nkwargs, **kwargs)
		result = (True, retval)

	except Exception,diag:
		result = (False, diag)
	
	return result

def test():
	funcs=(int, long, float)
	vals=(1234,12.34,'1234','12.34')
	
	for eachfunc in funcs:
		print '_'*100
		for eachval in vals:
			retval = testit(eachfunc,eachval)
			if retval[0]==True:
				print "%s(%s)= "%(eachfunc.__name__,eachval),retval[1]
			else:
				print "%s(%s)=failed "%(eachfunc.__name__,eachval),retval[1]


if __name__ == '__main__':
	test()
