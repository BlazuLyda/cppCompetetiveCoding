#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;

vector<pair<int,long long>> graph[2][5005];
bool visit[2][5005];
long long cost[5005];
long long tax[5005];

priority_queue<pair<long long,int>> que;

void dijkstra(int t)
{
	int w;
	long long k;
	
	que.push({0, 1});
	
	while(!que.empty())
	{
		w = que.top().ss;
		k = -que.top().ff;
		que.pop();
		
		if(visit[t][w])
			continue;
			
		visit[t][w] = 1;
		cost[w] += k;
			
		for (auto i : graph[t][w])
		{
			if(!visit[t][i.ff])
				que.push({-(k + i.ss), i.ff});
		}
	}
}

int main()
{
	scanf("%d", &n);
	
	int a, b;
	long long c;
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &tax[i]);
		
		tax[i] /= 2LL;
	}
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %lld", &a, &b, &c);
		
		graph[0][a].push_back({b, c});
		graph[1][b].push_back({a, c});
	}
	
	dijkstra(0);
	dijkstra(1);
	
	long long mini = tax[1];
	
	for (int i = 2; i <= n; ++i)
	{
		if(visit[0][i] && visit[1][i])
			mini = min(mini, cost[i] + tax[i]);
	}
	
	printf("%lld\n", mini);
	
	return 0;
}