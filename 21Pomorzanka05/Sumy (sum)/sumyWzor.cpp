#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, k;

vector<pair<int, int>> conns;
int cost[50005];
priority_queue<pair<int, int>> que;

int main()
{
	scanf("%d", &n);
	
	int a1, b;
	
	scanf("%d", &a1);
	
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &b);
		
		conns.push_back({b/a1, b%a1}); //koszt, wierzcholek
		que.push({-(b/a1), b%a1});
	}
	
	int c, w;
	
	fill(cost, cost+50005, INT_MAX);
	
	while(!que.empty())
	{
		c = -que.top().ff;
		w = que.top().ss;
		que.pop();
		
		if(cost[w] < INT_MAX)
			continue;
			
		cost[w] = c;
		
		for (auto i : conns)
		{
			if(cost[i.ss] == INT_MAX)
				que.push({-(c + i.ff), i.ss});
		}
	}
	
	cost[0] = 0;
	
	scanf("%d", &k);
	
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &b);
		
		if(cost[ b % a1 ] > b / a1)
			printf("NIE\n");
		else
			printf("TAK\n");
	}
	
	
	return 0;
}
