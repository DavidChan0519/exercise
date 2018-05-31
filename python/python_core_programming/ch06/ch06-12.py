#!/usr/bin/python

def findchr(aString, bChar):
	print "Index:",str(aString.find(bChar))

def rfindchr(aString, bChar):
	print "Last Index:",str(aString.rfind(bChar))

def subchr(aString, orgChar, newChar):
	newStr = aString.replace(orgChar, newChar)
	print "new str:",newStr
	print 'old str:',aString

findchr("I Love U", 'v')
rfindchr("I Love U", 'v')
subchr("I Love U", 'Love', 'hate')

