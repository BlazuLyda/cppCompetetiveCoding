#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m, q;

vector<pair<int, unsigned long long>> conns[500500];
bool visit[500500];
unsigned long long value[500500];

unsigned long long baza [64];

pair<unsigned long long, unsigned long long> check(unsigned long long k)
{
	for (unsigned long long i = 63; i < 64; --i)
	{	
		if(k & (1ULL<<i))
		{
			if(baza[i])
				k ^= baza[i];
			else
				return {i, k};
		}
	}
	
	return {0, 0};
}

void add(unsigned long long k)
{
	pair<unsigned long long, unsigned long long> roz = check(k);
	
	//printf("Check %llu -> {%llu, %llu}\n", k, roz.ff, roz.ss);
	
	if(roz.ss)
		baza[roz.ff] = roz.ss;
}

void DFS(int w, unsigned long long v)
{
	visit[w] = 1;
	value[w] = v;
	
	for (auto i : conns[w])
	{
		if(visit[i.ff])
		{
			add( v ^ i.ss ^ value[i.ff] );
		}
		else
			DFS( i.ff, v ^ i.ss );
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	int a, b;
	unsigned long long c;
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %llu", &a, &b, &c);
		
		conns[a].push_back({b, c});
		conns[b].push_back({a, c});
	}
	
	DFS(1, 0);
	
	scanf("%d", &q);
	
	while(q--)
	{
		scanf("%d %d %llu", &a, &b, &c);
		
		if(check(value[a] ^ value[b] ^ c).ss == 0)
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	
	return 0;
}
