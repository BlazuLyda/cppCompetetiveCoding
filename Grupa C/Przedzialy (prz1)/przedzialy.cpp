#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
vector<pair<int,int>> v;
vector<pair<int,int>> odp;

int main()
{
	scanf("%d", &n);
	
	int a, b;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		
		v.push_back({a, 0}); //początek przedziału
		v.push_back({b, 1}); //koniec przedziału
	}
	
	sort(v.begin(), v.end());
	
	int p = 0, k = 0;
	int l = 0;
	
	for (auto i : v)
	{
		if (i.ss) //koniec przedziału
		{
			l--;
			k = i.ff;

			if (l == 0) //jeżeli zamknąłem wszystkie otwarte przedziały
				odp.push_back({p, k});
		}
		else //początek przedziału
		{
			if (l == 0) //nie mam żadnego otwartego przedziału
				p = i.ff;
			
			l++;
		}
	}
	
	printf("%lu\n", odp.size());
	
	for (auto i : odp)
		printf("%d %d\n", i.ff, i.ss);
	
	return 0;
}
