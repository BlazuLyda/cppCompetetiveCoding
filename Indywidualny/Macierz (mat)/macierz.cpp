#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
int wyn = 0;
int tab[404][404];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			scanf("%d", &tab[i][j]);
	}
	
	int sum;
	pair <int,int> a, b, c, d;
	
	for (int i = 2; i < n; ++i) //kwadraty nieparzyste
	{
		for (int j = 2; j < n; ++j)
		{
			sum = 0;
			
			//printf("Center: (%d, %d)\n", i, j);
			
			a = {i-1, j-1};
			b = {i+1, j+1};
			c = {i-1, j+1};
			d = {i+1, j-1};
			
			for (int k = min(min(i-1, n-i), min(j-1, n-j)); k > 0; --k)
			{
				sum += tab[a.ff][a.ss] + tab[b.ff][b.ss] - tab[c.ff][c.ss] - tab[d.ff][d.ss];
				wyn = max(wyn, sum);
				
				//printf("\t(%d,%d) (%d,%d) (%d,%d) (%d,%d) --> %d\n", a.ff, a.ss, b.ff, b.ss, c.ff, c.ss, d.ff, d.ss, sum);
				
				--a.ff; --a.ss;
				++b.ff; ++b.ss;
				--c.ff; ++c.ss;
				++d.ff; --d.ss;
			}
		}
	}
	
	for (float i = 1.5; i <= n; ++i) //kwadraty nieparzyste
	{
		for (float j = 1.5; j <= n; ++j)
		{
			sum = 0;
			
			//printf("Center: (%f, %f)\n", i, j);
			
			a = {i-0.5, j-0.5};
			b = {i+0.5, j+0.5};
			c = {i-0.5, j+0.5};
			d = {i+0.5, j-0.5};
			
			for (float k = min(min(i-0.5, n-i+0.5), min(j-0.5, n-j+0.5)); k > 0; --k)
			{
				sum += tab[a.ff][a.ss] + tab[b.ff][b.ss] - tab[c.ff][c.ss] - tab[d.ff][d.ss];
				wyn = max(wyn, sum);
				
				//printf("\t(%d,%d) (%d,%d) (%d,%d) (%d,%d) --> %d\n", a.ff, a.ss, b.ff, b.ss, c.ff, c.ss, d.ff, d.ss, sum);
				
				--a.ff; --a.ss;
				++b.ff; ++b.ss;
				--c.ff; ++c.ss;
				++d.ff; --d.ss;
			}
		}
	}
	
	printf("%d\n", wyn);
	
	return 0;
}
