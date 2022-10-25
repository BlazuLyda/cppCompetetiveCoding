#include <bits/stdc++.h>

using namespace std;

int n, k;
int l, p;

int DP[50005][2][101];

bool grzyb[50005][2];

int main()
{
	scanf("%d %d", &n, &k);
	
	scanf("%d %d", &l, &p);
	
	int pos;
	
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &pos);
		
		grzyb[pos][0] = 1;
	}
	
	for (int i = 0; i < p; i++)
	{
		scanf("%d", &pos);
		
		grzyb[pos][1] = 1;
	}
	
	DP[1][0][0] = grzyb[1][0];
	DP[1][1][0] = -200000;
	DP[1][1][1] = grzyb[1][0] + grzyb[1][1];
	
	for (int i = 2; i <= n; i++)
	{
		DP[i][0][0] = DP[i-1][0][0] + grzyb[i][0];
		DP[i][1][0] = DP[i-1][1][0] + grzyb[i][1];
		
		//printf("position:%d cost:0 left:%d right:%d\n", i, DP[i][0][0], DP[i][1][0]);
		
		for (int j = 1; j <= k; j++)
		{
			DP[i][0][j] = max(DP[i-1][0][j], DP[i-1][1][j-1] + grzyb[i][1]) + grzyb[i][0];
			DP[i][1][j] = max(DP[i-1][1][j], DP[i-1][0][j-1] + grzyb[i][0]) + grzyb[i][1];
			
			//printf("position:%d cost:%d left:%d right:%d\n", i, j, DP[i][0][j], DP[i][1][j]);
		}
		//printf("\n");
	}	
	
	int wyn = 0;
	
	for (int j = 0; j <= k; j++)
	{
		wyn = max(wyn, DP[n][0][j]);
		wyn = max(wyn, DP[n][1][j]);
	}
	
	printf("%d\n", wyn);
	
	return 0;
}