file = open('wout')

a = 0

for line in file:
	a = a ^ int(line)
	
print(a)