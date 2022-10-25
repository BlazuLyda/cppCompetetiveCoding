#include <bits/stdc++.h>

using namespace std;

int n, m;

int part[200200];

int main()
{
	scanf("%d %d", &n, &m);
	
	int a, b;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		
		for (int j = 0; j < a; ++j)
		{
			scanf("%d", &b);
			
			++part[b];
		}
	}
	
	int idx = 1, mx = 0;
	
	for (int i = 1; i <= m; ++i)
	{
		if(part[i] > mx)
		{
			mx = part[i];
			idx = i;
		}
	}
	
	printf("%d\n", idx);
	
	return 0;
}