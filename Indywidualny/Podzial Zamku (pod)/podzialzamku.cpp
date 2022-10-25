#include <bits/stdc++.h>

using namespace std;

int n, wyn;
vector<int> conns[200002];

int DFS(int w, int o)
{
	int a, siz = 1;
	
	for (auto i : conns[w])
	{
		if(i != o)
		{
			a = DFS(i, w);
			wyn = min(wyn, abs(n - 2*a));
			siz += a;
		}
	}
	
	return siz;
}

int main()
{
	scanf("%d", &n);
	
	wyn = n;
	
	int a, b;
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	DFS(1, 0);
	
	printf("%d\n", wyn);
	
	return 0;
}