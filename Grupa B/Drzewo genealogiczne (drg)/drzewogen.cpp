#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int wyn = 0;
int n;

pair<int,int> conns[1000100];
vector<int> val;

void DFS(int w, int a, int h)
{
	if(w == (int)val.size())
	{
		val.push_back(a);
		wyn = max(wyn, h);
		return;
	}
	
	if(a < val[w])
	{
		if(!conns[w].ff)
			conns[w].ff = val.size();
			
		DFS(conns[w].ff, a, h+1);
	}
	else
	{
		if(!conns[w].ss)
			conns[w].ss = val.size();
			
		DFS(conns[w].ss, a, h+1);
	}
	
}


int main()
{
	scanf("%d", &n);
	
	int a;
	
	scanf("%d", &a);
	
	val.push_back(a);
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a);
		
		DFS(0, a, 0);
	}
	
	/*
	for (int i = 0; i < n; i++)
	{
		printf("%d(%d): (%d, %d)\n", i, val[i], conns[i].ff, conns[i].ss);
	}
	*/
	
	
	printf("%d\n", wyn);
}