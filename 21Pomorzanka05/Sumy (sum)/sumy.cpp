#include <bits/stdc++.h>

using namespace std;

const int inf = 1001001001;

int n, k;

int first[5005], firstLas[5005], cycle[5005], newOrd[5005];

int main()
{
	scanf("%d", &n);
	
	int a, aLas, num;
	
	//ustalanie wstępnych wartości
	scanf("%d", &aLas);
	
	fill(firstLas, firstLas + 5005, inf);
	
	firstLas[0] = 0;
	
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &a);
		
		if(a >= firstLas[a % aLas]) //jeżeli element a jest niepotrzebny w zbiorze A
			continue;
			
		//tworzenie nowego cyklu modulo
		num = 0;
		
		for (int j = 0; j < a; ++j)
		{
			cycle[num] = j;
			
			num += aLas;
			
			if(num >= a) //szybsze modulowanie przy dodawaniu
				num -= a;
		}
		
		//ustalanie nowego first[]
		int c, nww = a * aLas;
		
		for (int j = 0; j < aLas; ++j)
		{
			newOrd[j] = firstLas[j] % a;
		}
		
		for (int j = 0; j < a; ++j)
		{
			first[j] = inf;
			
			c = cycle[j];
					
			for (int j2 = 0; j2 < aLas; ++j2)
			{
				if(firstLas[j2] >= inf)
					continue;
				
				num = (c - cycle[newOrd[j2]]) * aLas;
				
				if(num < 0)
					num += nww;
				
				first[j] = min(first[j], firstLas[j2] + num);
			}
		}
		
		/*
		printf("\n\tNew element: %d", a);
		printf("\nCycle:");
		for (int j = 0; j < a; ++j)
			{
				printf(" %d", cycle[j]);
			}
		printf("\nFirst:");
		for (int j = 0; j < a; ++j)
			{
				printf(" %d", first[j]);
			}
		printf("\n");
		*/
		
		swap(aLas, a);
		swap(firstLas, first);
	}
	
	scanf("%d", &k);
	
	int b, mod;
	
	while(k--)
	{
		scanf("%d", &b);
		
		mod = b % aLas;
		
		if(b >= firstLas[mod])
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	
	return 0;
}
