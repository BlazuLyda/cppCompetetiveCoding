#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int pref[200][200];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	int a, b, c, d;
	
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		
		a++; b++;
		
		for (int x = a; x < a+c; ++x)
		{
			for (int y = b; y < b+d; ++y)
			{
				pref[x][y] = 1;
			}
		}
	}
	
	int l, h;
	
	scanf("%d %d", &l, &h);
	
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= m; ++y)
		{
			pref[x][y] += pref[x-1][y] + pref[x][y-1] - pref[x-1][y-1];
		}
	}
	
	int wyn = 0;
	
	for (int x = l; x <= n; ++x)
	{
		for (int y = h; y <= m; ++y)
		{
			if(pref[x][y] - pref[x-l][y] - pref[x][y-h] + pref[x-l][y-h] == 0)
				++wyn;
		}
	}
	
	printf("%d\n", wyn);
	
	return 0;
}
