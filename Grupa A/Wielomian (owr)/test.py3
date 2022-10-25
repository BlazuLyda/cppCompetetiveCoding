wynik = 0.0

for a in range(1, 1000000000):
	wynik = wynik + 1/a
	
	if (a % 100000000 == 0):
		print(a)
	
print(wynik)
	
