a = 1
b = 1


for x in range(0, 1000000):
	oldb = b
	b = a + b;
	a = oldb
	if b % 521 == 0:
		print("essa: "+str(b))
		break
	