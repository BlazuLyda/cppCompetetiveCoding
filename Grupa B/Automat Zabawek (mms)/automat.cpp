#include <bits/stdc++.h>

using namespace std;

int n, l;
bool spec[300300];
vector<int> conns[300300];

int DFS(int w) 
{
	if(conns[w].size() == 0) 
	{
		++l;
		return 1;
	}
				
	int res;
		
	if(spec[w]) 
	{
		res = 300300;
		
		for (auto i : conns[w]) 
		{
			res = min(res, DFS(i));
		}
	}
	else
	{
		res = 0;
		
		for (auto i : conns[w]) 
		{
			res += DFS(i);
		}
	}
	
	//printf("NOD:%d Result:%d\n", w, res);
	
	return res;
}

int main() 
{
	scanf("%d", &n);
	
	int pom;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &pom);
		
		spec[i] = (bool)pom;
	}
	
	int a;
	
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &a);
		
		conns[a].push_back(i);
	}
	
	int result = DFS(1);
	
	printf("%d\n", l - result + 1);
	
	return 0;
}