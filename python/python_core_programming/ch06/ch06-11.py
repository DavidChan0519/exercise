#!/usr/bin/python



def convert_2_int(a):
	a_str= ''
	strList = a.split('.',4)
	print strList
	for i in strList:
		a_tem = bin(int(i))[2:]
		if len(a_tem) != 8:
			a_str += '0'*(8-len(a_tem))+a_tem
		else:
			a_str += a_tem
	
	result = int(a_str,2)
	print 'R:%d'%result

a=raw_input("Please input IP addr:")
convert_2_int(a)

def convert_2_IP(b):
	binStr=bin(int(b))[2:]
	print binStr
	if len(binStr) != 32:
		binStr = '0'*(32-len(binStr)) + binStr
	print binStr

	a1=binStr[0:8]
	a2=binStr[8:16]
	a3=binStr[16:24]
	a4=binStr[24:32]
	print "IP:"+str(int(a1,2))+'.'+str(int(a2,2))+'.'+str(int(a3,2))+'.'+str(int(a4,2))


b=raw_input("Please input int num:")
convert_2_IP(b)


