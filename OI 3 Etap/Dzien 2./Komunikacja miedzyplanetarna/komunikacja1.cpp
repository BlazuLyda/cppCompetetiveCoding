#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
vector<pair<pair<long long, long long>, int>> tab;
long long odp[100100];

void odpowiedz(long double answ)
{
	cout << (long double)((long double)answ / (long double)1000.0) << "\n";
}

long double ldpow(long double v)
{
	return (long double)(v * v);
}

long double ldabs(long double v)
{
	if(v < 0)
		return -v;
		
	return v;
}

long long labs(long long v)
{
	if(v < 0)
		return -v;
		
	return v;
}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	
	cin >> n;
	
	tab.resize(n);
	
	long long x, y, x0, y0;
	
	bool case2 = 1;
	
	cin >> x0 >> y0;
		
	tab[0] = {{x0 * 1000ll, y0 * 1000ll}, 0};
	
	cin >> x >> y;
		
	tab[1] = {{x * 1000ll, y * 1000ll}, 1};
	
	for (int i = 2; i < n; ++i)
	{
		cin >> x >> y;
		
		if(((x - x0) * (tab[i-1].ff.ss - y0) - (tab[i-1].ff.ff - y0) * (y - y0)) != 0)
			case2 = 0;
		
		x = x * 1000ll;
		y = y * 1000ll;
		
		tab[i] = {{x, y}, i};
	}
	
	if(minx == maxx || miny == maxy)
	{
		sort(tab.begin(), tab.end());
		
		long long w = 0;
		
		for (int i = 1; i < n; ++i)
		{
			w += max(labs(tab[i].ff.ff - tab[0].ff.ff), labs(tab[i].ff.ss - tab[0].ff.ss));
		}
		
		odp[tab[0].ss] = w;
		
		for (int i = 1; i < n; ++i)
		{
			w += (i*2ll - n) * max(labs(tab[i].ff.ff - tab[i-1].ff.ff), labs(tab[i].ff.ss - tab[i-1].ff.ss));
			
			odp[tab[i].ss] = w;
		}
		
		for (int i = 0; i < n; ++i)
		{
			odpowiedz(odp[i]);
		}
		
	}
	else
	{
		long double w = 0;
		
		for (int i = 0; i < n; ++i)
		{
			w = 0;
			
			for (int j = 0; j < n; ++j)
			{
				w += sqrtl(ldpow(tab[i].ff.ff - tab[j].ff.ff) + ldpow(tab[i].ff.ss - tab[j].ff.ss));
			}
			
			odpowiedz(w);
		}	
	}
	
	return 0;
}