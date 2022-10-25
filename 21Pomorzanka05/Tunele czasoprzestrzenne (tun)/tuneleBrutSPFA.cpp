#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int n, q;
set<pair<pair<int, int>, int>> conns;
pair<pair<int,int>, int> input[4000];
queue<pair<pair<int,int>, int>>> que;
int cost[2002];

int main()
{
	scanf("%d %d", &n, &q);
	
	int a, b, c, d;
	char t;
	
	for (int k = 0; k < q; ++k);
	{
		scanf(" %c", &t);
		
		if(t == 'B')
		{
			scanf("%d %d %d", &a, &b, &c);
			
			input[k] = {{a, b}, c};
			conns.insert({{a, b}, c});
		}
		else
		{
			scanf("%d", &d);
			
			conns.erase(input[d]);
		}
		
		fill(cost, cost + n, inf);
		cost[a] = 0;
		
		for (auto i : conns) que.push(i);
		
		for (int i = 0; i < n; ++i)
		{
			a = que.front().ff.ff;
			b = que.front().ff.ss;
			c = que.front().ss;
			que.pop();
			
			if(cost[b] < cost[a] + c)
			{
				cost[b] = cost[a] + c;
				que.push({{a, b}, c});
			}
		}
		
		if(!que.empty())
		{
			while(!que.empty())	que.pop();
			
			printf("NIE\n");
		}
		else
			printf("TAK\n");
		
	}
	
	return 0;
}
