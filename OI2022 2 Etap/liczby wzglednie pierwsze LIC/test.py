primes = [2]
num = 3
il = 2

while True:
	b = True
	
	for p in primes:
		if num % p == 0:
			b = False
			break
	
	if b:
		if il * num < 10**14:
			primes.append(num)
			il *= num
		else:
			break
		
	num += 2
	
print("last prime:", num)
print("n:", il)
print(primes)
