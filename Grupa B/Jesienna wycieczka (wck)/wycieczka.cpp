#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> conns[100100];
int depth[100100];
bool visit[100100];

int DFS(int w, int d) //zwraca funkcję low
{
	int back = 0, low = 100100, pom; //liczba krawędzi zwrotnych nad wierzchołek, najwyższa krawędź zwrotna
	
	depth[w] = d;
	visit[w] = 1;
	
	//printf("Wierzcholek:%d  glebokosc:%d\n", w, d);
	
	for (auto i : conns[w])
	{	
		if (visit[i]) //wierzchołek już odwiedzony
		{
			if(depth[i] + 1 == d) //jeżeli to ojciec
				continue;
			
			if ( (d - depth[i]) % 2 )
			{
				printf("JEST\n");
				exit(0);
			}
			
			low = min(low, depth[i]);
			back++;
		}
		
		else //wierzcholek jeszcze nie odwiedzony
		{	
			pom = DFS(i, d+1);
			
			low = min(low, pom);
			
			if( pom < d )
				back++;
		}
	}
	
	if( back >= 2 )
	{
		printf("JEST\n");
		exit(0);
	}
	
	return low;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	int a, b;
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	for (int i = 0; i <= n; ++i)
	{
		if(!visit[i])
			DFS(i, 0);
	}
	
	printf("BRAK\n");
	
	return 0;
}
