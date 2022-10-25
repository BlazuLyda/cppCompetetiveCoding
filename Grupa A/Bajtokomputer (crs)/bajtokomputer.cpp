#include <bits/stdc++.h>

using namespace std;

const int inf = 10000000;

int n, wyn;
int tab[1000010];
int DP[1000010][3];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tab[i]);
	}
	
	fill(DP[1], DP[1] + 3, inf); //wartości początkowe
	DP[1][tab[1] + 1] = 0;
	
	for (int i = 2; i <= n; i++)
	{
		if(tab[i] == -1)
		{
			DP[i][0] = DP[i-1][0];
			DP[i][1] = inf;
			DP[i][2] = DP[i-1][2] + 2;
		}
		else if(tab[i] == 0)
		{
			DP[i][0] = DP[i-1][0] + 1;
			DP[i][1] = min(DP[i-1][0], DP[i-1][1]);
			DP[i][2] = DP[i-1][2] + 1;
		}
		else
		{
			DP[i][0] = DP[i-1][0] + 2;
			DP[i][1] = DP[i-1][0] + 1;
			DP[i][2] = min(min(DP[i-1][0], DP[i-1][1]), DP[i-1][2]);
		}
	}
	
	int wyn = min(min(DP[n][0], DP[n][1]), DP[n][2]);
	
	if(wyn >= inf)
		printf("BRAK\n");
	else
		printf("%d\n", wyn);
	
	return 0;
}