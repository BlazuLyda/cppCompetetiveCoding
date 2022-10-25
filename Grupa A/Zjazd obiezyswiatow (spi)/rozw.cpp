#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool bruh[251];

struct matrix
{
	bool mat[251][251];
	
	void print()
	{
		printf("----------------------------\n");
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%d ", mat[i][j]);
			}
			
			printf("\n");
		}
		
		printf("----------------------------\n");
	}
};

matrix graph, guys, zero;

matrix operator*(matrix a, matrix b)
{
	matrix resMul = zero;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{	
			for (int k = 1; k <= n; ++k)
			{
				if(a.mat[i][k] && b.mat[k][j])
				{	
					resMul.mat[i][j] = 1;
					break;
				}
			}
		}
	}
	
	return resMul;
}

bool check(int p)
{
	matrix res = guys, mul = graph;
	
	while(p)
	{	
		if(p & 1)
			res = res * mul;
		
		mul = mul * mul;
		p >>= 1;
	}
	
	bool b;
	
	for (int j = 1; j <= n; ++j)
	{
		b = 1;
		
		for (int i = 1; i <= n; ++i)
		{
			b = b && (bruh[i] == res.mat[i][j]);
		}
		
		if(b)
			return 1;
	}
	
	return 0;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	int a, b;
	
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &a);
		
		guys.mat[a][a] = 1;
		bruh[a] = 1;
	}
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		
		graph.mat[a][b] = 1;
	}
	
	//binsearch
	int p = 0, k = n*n, s;
	
	while(p < k)
	{
		s = (p + k) / 2;
		
		printf("p:%d s:%d k:%d\n", p, s, k);
		
		if(check(s))
			k = s;
		else
			p = s + 1;
	}
	
	if(check(p))
		printf("TAK\n%d\n", p);
	else
		printf("NIE\n");
	
	return 0;
}