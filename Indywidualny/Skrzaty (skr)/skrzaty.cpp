#include <bits/stdc++.h>

using namespace std;

int n, m;
bitset<1000100> block;
int nums[1000100];
queue<int> act, actBin, pot, potBin;


int main()
{
	scanf("%d %d", &n, &m);
	
	act.push(1);
	
	for (int i = 2; i <= n; ++i)
		pot.push(i);
	
	
	int a;
	
	for (int t = 0; t < m; ++t)
	{
		scanf("%d", &a);
		
		for (int i = 0; i < a; ++i)  //Kmax razy
		{
			scanf("%d", &nums[i]);
			block[nums[i]] = 1;
		}
		
		while (!act.empty() && block[act.front()])  //maks Kmax razy
		{
			actBin.push(act.front());
			act.pop();
		}
			
		if (!act.empty())
		{
			while (!pot.empty())
			{
				if (block[pot.front()])  //maks Kmax razy
					potBin.push(pot.front());
					
				else  //maks n razy
				{
					if (pot.front() == n) //doszlismy do konca
					{
						printf("%d\n", t);
						exit(0);
					}
					
					act.push(pot.front());
				}
				
				pot.pop();
			}
			
			swap(pot, potBin);
		}
		
		while (!actBin.empty())  //maks Kmax razy
		{
			act.push(actBin.front());
			actBin.pop();
		}
		
		for (int i = 0; i < a; ++i)  //Kmax razy
			block[nums[i]] = 0;
	}
	
	printf("%d\n", m);
	
	return 0;
}
