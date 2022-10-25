#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<int> conns[100009];
bool odp;
bitset<100009> visit;
int depth[100009];

int DFS(int w, int d, int o)
{
	int low = d+1;
	
	visit[w] = 1;
	depth[w] = d;
	
	bool b = 0;
	
	//printf("Wchodze do %d\n", w);
	
	for (auto i : conns[w])
	{
		if(!visit[i])
			low = min(low, DFS(i, d+1, w));
		else if(i != o || b)
			low = min(low, depth[i]);
		else
			b = 1;
	}
	
	//printf("w:%d depth:%d low:%d\n", w, d, low);
	
	if((low >= d && w != 1) || (low > 1 && w == 1))
		odp = 0;
	
	return low;
}

int main()
{
	scanf("%d", &t);
	
	int a, b;
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		
		for (int i = 1; i <= n; i++)
		{
			conns[i].clear();
		}
		
		visit.reset();
		
		odp = 1;
		
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &a, &b);
			
			conns[a].push_back(b);
			conns[b].push_back(a);
		}
		
		DFS(1, 1, 0);
		
		for (int i = 1; i <= n; ++i)
		{
			if(!visit[i])
			{
				odp = 0;
				break;
			}
		}
		
		if(odp)
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	
	
	
	return 0;
}