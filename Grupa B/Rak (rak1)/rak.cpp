#include <bits/stdc++.h>

using namespace std;

int n, m;
int t = 1;

vector<int> graph[20200], graphr[20200];
int tout[20200];
bool visit[20200];
int spojna[20200];
int siz[20200];

void DFS1(int w)
{
	visit[w] = 1;
	
	printf("\tw:%d type:%d\n", w/2, (w&1));
	
	for(auto i : graph[w])
	{
		if(visit[i] == 0)
		{
			DFS1(i);
		}
	}
	
	tout[++t] = w;
	
	printf("w:%d type:%d time:%d\n", w/2, (w&1), t);
}

void DFS2(int w)
{
	spojna[w] = t;
	
	if(spojna[w^1] != t)
		++siz[t];
	
	for(auto i : graphr[w])
	{
		if(spojna[i] == 0)
			DFS2(i);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	int a, b, c;
	
	for (int i = 0; i < n; i++) 			//2*n - wierzcholek normalny
	{										//2*n+1 - wierzcholek wspak
		scanf("%d %d %d", &a, &b, &c);
		
		if(c)
		{
			graph[2*a].push_back(2*b+1);
			graph[2*b+1].push_back(2*a);
			
			graphr[2*b+1].push_back(2*a);
			graphr[2*a].push_back(2*b+1);
		}
		else
		{
			graph[2*a].push_back(2*b);
			graph[2*b+1].push_back(2*a+1);
			
			graphr[2*b].push_back(2*a);
			graphr[2*a+1].push_back(2*b+1);
		}
	}
	
	for (int i = 2; i <= 2*n+1; ++i)
	{
		if(!visit[i])
			DFS1(i);
	}
	
	t = 1;
	
	for (int i = 2*n+1; i > 1; --i)
	{
		printf("tout:%d w:%d type:%d\n", i, spojna[i]/2, (spojna[i]&1));
		
		if(spojna[tout[i]] == 0)
		{
			++t;
			DFS2(tout[i]);
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		printf("w:%d spojna:%d size:%d\n", i, spojna[i], siz[spojna[i]]);
		
		//printf("%d\n", siz[spojna[i*2+1]] - 1);
	}
	
	
	return 0;
}