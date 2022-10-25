#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2};

int main()
{
	bool b;
	
	for (int i = 3; i < 3163; i+=2)
	{
		b = 1;
		
		for (auto j : primes)
		{
			if(i % j == 0)
			{
				b = 0;
				break;
			}
		}
		
		if(b)
			primes.push_back(i);
	}
	
	printf("int primes[%d] = {", (int)primes.size());
	
	for (auto i : primes)
	{
		printf("%d, ", i);
	}
	
	printf("\n");
	
	return 0;
}