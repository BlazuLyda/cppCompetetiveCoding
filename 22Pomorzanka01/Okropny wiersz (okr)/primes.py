def fpow(a, p, m):
	wyn = 1
	print(p)
	while p:
		print("a:{} p:{}".format(a, p))
		if (p%2 == 1):
			wyn = (wyn * a) % m
		a = (a * a) % m
		p = int(p / 2)
	return wyn
	
print(fpow(31, 1000000005, 1000000007))
		
