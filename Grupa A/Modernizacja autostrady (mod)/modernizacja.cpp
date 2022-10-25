#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct tree 
{
	vector<int> graph[500005];
	int anc[500005];
	
	void rmConn(int a, int b)
	{
		graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
		graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
	};
	
	void addConn(int a, int b)
	{
		graph[a].push_back(b);
		graph[b].push_back(a);
	};

	pair<int, int> DFS1(int w, int o)
	{
		pair<int,int> res = {w, 0}, out;
		
		anc[w] = o;
		
		for(auto i : graph[w])
		{
			if(i != o)
			{
				out = DFS1(i, w);
				
				if(out.ss > res.ss)
					res = out;
			}
		}
		
		++res.ss;
		
		return res;
	};
	
	vector<int> searchMiddle(int w)
	{
		int w1, w2, l, nod;
		pair<int,int> p;
		
		p = DFS1(w, 0); //searching for the first dot
		
		w1 = p.ff;
		
		p = DFS1(w1, 0); //searching for the second nod and length
		
		w2 = p.ff;
		l = p.ss - 1;
		nod = w2;
		
		for (int i = 0; i < (l/2); ++i) //searching for the rout int the middle
		{
			nod = anc[nod];
		}
		
		vector<int> res = {w1, w2, nod, l};
			
		return res;
	};
};

int n;
tree input;

int main()
{
	scanf("%d", &n);
	
	int a, b;
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		
		input.addConn(a, b);
	}
	
	int ans1[5]; //ans2[5];
	vector<int> v1, v2, v3, v4;
	
	v1 = input.searchMiddle(1);				 //dividing the tree
	input.rmConn(v1[2], input.anc[v1[2]]);	//
	
	ans1[1] = v1[2];
	ans1[2] = input.anc[v1[2]];
	
	v2 = input.searchMiddle(ans1[1]);   //resolving the subtrees
	v3 = input.searchMiddle(ans1[2]);  //
	
	ans1[3] = v2[2];
	ans1[4] = v3[2];
	
	input.addConn(v2[2], v3[2]); //merging the subtrees
	
	v4 = input.searchMiddle(1);
	
	ans1[0] = v4[3];
	
	printf("%d %d %d %d %d", ans1[0], ans1[1], ans1[2], ans1[3], ans1[4]);
	
	return 0;
}