#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
long long m, wyn;
vector<pair<long long, bool>> v;

int main()
{
	scanf("%d %lld", &n, &m);
	
	long long a, b;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &a, &b);
		
		if ( a > b )
		{
			v.push_back({b, 0}); //początek przedziału
			v.push_back({a, 1}); //koniec przedziału
		}
	}
	
	sort(v.begin(), v.end());
	
	wyn = m;
	
	long long p = 0, k = 0;
	int l = 0;
	
	for (auto i : v)
	{
		if (i.ss) //koniec przedziału
		{
			l--;
			k = i.ff;
			
			//printf("Koniec p:%lld k:%lld\n", p, k);
			
			if (l == 0) //jeżeli zamknąłem wszystkie otwarte przedziały
				wyn += 2LL * (k - p);
		}
		else //początek przedziału
		{
			if (l == 0) //nie mam żadnego otwartego przedziału
				p = i.ff;
			
			//printf("Poczatek p:%lld k:%lld\n", p, k);
			
			l++;
		}
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}
