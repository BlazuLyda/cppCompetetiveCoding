#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
vector<pair<long long, long long>> tab;

long double ldpow(long double v)
{
	return (long double)(v * v);
}

void odpowiedz(long double answ)
{
	cout << (long double)((long double)answ / (long double)1000.0) << "\n";
}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
		
	cin >> n;
		
	tab.resize(n);
		
	long long x, y;
			
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		
		x = x * 1000ll;
		y = y * 1000ll;
		
		tab[i] = {x, y};
	}

	long double w = 0;
			
	for (int i = 0; i < n; ++i)
	{
		w = 0;
		
		for (int j = 0; j < n; ++j)
		{
			w += sqrtl(ldpow(tab[i].ff - tab[j].ff) + ldpow(tab[i].ss - tab[j].ss));
		}
		
		odpowiedz(w);
	}
	
	return 0;
}	