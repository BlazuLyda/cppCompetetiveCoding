//autor rozwiązania: Błażej Łytkowski

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const long long inf = 10000000000000000;

int n, m, s, k;
long long t;

map<pair<int,int>, long long> vert;

long long MinCost[10100]; //<przesiadki, czas>

pair<long long, long long> line[25005]; //czasy lini
vector<pair<int,long long>> route[25005]; //droga lini
vector<long long> przejazd[25005];

priority_queue<pair<long long, pair<int,int>>;

long long czas(long long c, long long x, long long y)
{
	if(x > c)
		return x;
		
	return c + (y - ((c-x) % y));
}

int main()
{
	scanf("%d %d %d %d %lld", &n, &m, &s, &k, &t);
	
	int a, b;
	long long c;
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %lld", &a, &b, &c);
		
		if(a > b)
			swap(a, b);
			
		vert[{a,b}] = c;
	}
	
	int l, v1, v2;
	long long x, y, las = 0;
	
	for (int i = 0; i < s; ++i)
	{
		scanf("%d %lld %lld", &l, &x, &y);
		
		line[i].ff = x;
		line[i].ss = y;
		
		scanf("%d", &v1);
		las = x;
		
		przejazd[i].push_back(0ll);
		route[i].push_back({v1, x});
		
		for (int j = 1; j < l; ++j)
		{
			scanf("%d", &v2);
			
			las += vert[{min(v1, v2), max(v1, v2)}];
			przejazd[i].push_back(vert[{min(v1, v2), max(v1, v2)}]);
			
			route[i].push_back({v2, las}); //koszt v1 do vi
			
			v1 = v2;
		}
	}
	
	//dijkstra * k
	fill(MinCost, MinCost+n+1, inf); //początkowe wartości
	MinCost[1] = t;
	
	long long locCost;
	int place;
	
	int r;
	
	for (int j = 0; j <= k; ++j)
	{
		//printf("\tKolejka: %d\n", j);
		
		for (int i = 0; i < s; ++i) //przejechanie się przez całą linię autobusową
		{
			x = line[i].ff;
			y = line[i].ss;
			
			locCost = czas(MinCost[route[i][0].ff], x, y); //kiedy możemy odjechać z 1. przystanka
			
			que.push({-locCost, {i, route[i][0].ff}});
			
			//printf("Linia:%d x:%lld y:%lld czasrozpoczecia:%lld\n", i, x, y, locCost);
			
			
			
		}
		
		while(!que.empty())
		{
			place = que.ss.ss;
			locCost += przejazd[i][r];
				
			MinCost[place] = min(MinCost[place], locCost); //czy dojechaliśmy taniej
				
			locCost = min(locCost, czas(MinCost[place], route[i][r].ss, y));
				
			locCost = min(locCost, inf);
		}
		
		for (int r = 1; r < (int)route[i].size(); r++) //przejazd przez linię
			{
				place = route[i][r].ff;
				locCost += przejazd[i][r];
				
				MinCost[place] = min(MinCost[place], locCost); //czy dojechaliśmy taniej
				
				locCost = min(locCost, czas(MinCost[place], route[i][r].ss, y));
				
				locCost = min(locCost, inf);
				
				//printf("Jestem w v:%d mincost:%lld   locCost:%lld\n", place, MinCost[place], locCost);
			}
	}
	
	if(MinCost[n] < inf)
		printf("%lld\n", MinCost[n]);
	else
		printf("NIE\n");
	
	
	return 0;
}