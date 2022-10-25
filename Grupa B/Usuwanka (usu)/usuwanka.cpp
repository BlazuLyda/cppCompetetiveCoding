#include <bits/stdc++.h>

using namespace std;

int n;
int tab[200200];
priority_queue<int> que;

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tab[i]);
	}
	
	int wyn = 0, p = 0, k = 1;
	
	while (k <= n)
	{
		for (; p < k; ++p)
			que.push(min(tab[p] + 1, n - p));
			
		++ wyn;
		k += que.top();
		que.pop();
	}
	
	printf("%d\n", wyn);
	
	return 0;
}