#include <bits/stdc++.h>

using namespace std;

int n;
int tab[3], cnt[3][3], arr[1000];

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		
		--arr[i];
		
		++tab[arr[i]];
	}
	
	//printf("1:%d 2:%d 3:%d\n", tab[0], tab[1], tab[2]);
	
	for (int i = 0; i < tab[0]; i++)
	{
		++cnt[arr[i]][0];
	}
	
	for (int i = tab[0]; i < (tab[0] + tab[1]); i++)
	{
		++cnt[arr[i]][1];
	}
	
	for (int i = tab[0] + tab[1]; i < (tab[0] + tab[1] + tab[2]); i++)
	{
		++cnt[arr[i]][2];
	}
	
	int singl = 0, doubl = 0;
	
	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", cnt[i][j]);
		}
		
		printf("\n");
	}
	*/
	
	singl = min(cnt[0][1], cnt[1][0]) + min(cnt[1][2], cnt[2][1]) + min(cnt[2][0], cnt[0][2]);
	
	doubl = (n - singl*2 - cnt[0][0] - cnt[1][1] - cnt[2][2]) * 2 / 3;
	
	//printf("s:%d d:%d\n", singl, doubl);
	
	printf("%d", singl + doubl);
	
	
	return 0;
}