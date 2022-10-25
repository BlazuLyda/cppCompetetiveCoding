#include <bits/stdc++.h>

using namespace std;

int n;
int tab[1100][1100], mx[1100][1100];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			scanf("%d", &tab[i][j]);
	}
	
	int x, y;
	
	mx[3][2] = tab[1][1];
	mx[2][3] = tab[1][1];
	
	for (int i = 2; i <= n; ++i)
	{
		x = i;
		
		for (y = 1; y <= i; ++y)
		{	
			//printf("x:%d y:%d mx:%d ", x, y, mx[x][y]);
			
			if(mx[x][y] == 0)
				tab[x][y] = 0;
			
			tab[x][y] += mx[x][y];
			
			//printf("wyn:%d\n", tab[x][y]);
			
			mx[x+2][y+1] = max(mx[x+2][y+1], tab[x][y]);
			mx[x+2][y-1] = max(mx[x+2][y-1], tab[x][y]);
			mx[x+1][y+2] = max(mx[x+1][y+2], tab[x][y]);
			mx[x-1][y+2] = max(mx[x-1][y+2], tab[x][y]);
			
			--x;
		}
	}
	
	for (int i = 2; i <= n; ++i)
	{
		y = i;
		
		for (x = n; x >= i; --x)
		{	
			//printf("x:%d y:%d mx:%d ", x, y, mx[x][y]);
			
			if(mx[x][y] == 0)
				tab[x][y] = 0;
			
			tab[x][y] += mx[x][y];
			
			//printf("wyn:%d\n", tab[x][y]);
			
			mx[x+2][y+1] = max(mx[x+2][y+1], tab[x][y]);
			mx[x+2][y-1] = max(mx[x+2][y-1], tab[x][y]);
			mx[x+1][y+2] = max(mx[x+1][y+2], tab[x][y]);
			mx[x-1][y+2] = max(mx[x-1][y+2], tab[x][y]);
			
			++y;
		}
	}
	
	printf("%d\n", tab[n][n]);
	
	return 0;
}
