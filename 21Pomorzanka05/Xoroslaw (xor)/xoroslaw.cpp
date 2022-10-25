#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const int R = 524288;

vector<unsigned int> tree[2*R];sas

int n;

map<unsigned int, int> op;

void update(int w, int p, int k, int x, int y, unsigned int v)
{
	if(y < p || k < x)
		return;
	
	if(x <= p && k <= y)
	{
		tree[w].push_back(v);
		return;
	}
	
	update(w*2, p, (p+k)/2, x, y, v);
	update(w*2+1, (p+k)/2+1, k, x, y, v);
}

void DFS(int w, vector<unsigned int> base)
{	
	for(unsigned int v : tree[w])
	{
		for (unsigned int i = 30; i < 31; --i)
		{
			if(v & (1U<<i))
			{
				if(base[i])
					v ^= base[i];
				else
				{
					base[i] = v;
					break;
				}
			}
		}
	}
	
	if(w >= R)
	{ 
		if(w < n + R)
		{
			unsigned int res = 0;
			
			for (unsigned int i = 30; i < 31; --i)
			{
				if( !(res & (1U<<i)) )
					res ^= base[i];
			}
			
			printf("%u\n", res);
		}
		
		return;
	}
	
	DFS(w*2, base);
	DFS(w*2+1, base);
}

int main()
{
	scanf("%d", &n);
	
	int a;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		
		if(a > 0)
			op[a] = i;
		else
		{
			update(1, 0, R-1, op[-a], i-1, -a);
			op.erase(-a);
		}
	}
	
	for (auto i : op)
		update(1, 0, R-1, i.ss, n-1, i.ff);
	
	vector<unsigned int> base;
	base.resize(32);
	fill(base.begin(), base.end(), 0);
	
	DFS(1, base);
	
	return 0;
}
