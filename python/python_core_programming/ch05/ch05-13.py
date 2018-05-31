def convert(h,m):
	return h*60+m

while True:
		h = input("Please input hour:")
		m = input("Please input minutes:")
		if (0<= m <= 60) and (0 <= h <= 24):
			print "%d minutes" %convert(h,m)
		else:
			print "invalid input param"