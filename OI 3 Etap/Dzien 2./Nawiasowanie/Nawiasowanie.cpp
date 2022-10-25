#include <bits/stdc++.h>

using namespace std;

int n;
int tab[1000001];
vector<int> naw;

bool sprawdz()
{
	int sum = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		
		
		sum += naw[tab[i]-1];
		
		if(sum < 0)
			return 0;
	}
	
	return 1;
}

bool brut(int sum)
{
	if((int)naw.size() == n)
	{
		if(sum == 0)
			return sprawdz();
			
		return 0;
	}
	
	if(sum < 0)
		return 0;
		
	naw.push_back(1);
	
	if(brut(sum + 1))
		return 1;
	
	naw.pop_back();
	
	naw.push_back(-1);
	
	if(brut(sum - 1))
		return 1;
		
	naw.pop_back();
	
	return 0;
}

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &tab[i]);
	}
	
	if(n % 2 != 0)
	{
		printf("NIE\n");
		return 0;
	}
	
	if(brut(0))
	{
		for (int i = 0; i < n; i++)
		{
			if(naw[i] == 1)
				printf("(");
			else
				printf(")");
		}
		printf("\n");	
	}
	else
		printf("NIE\n");
	
	return 0;
}