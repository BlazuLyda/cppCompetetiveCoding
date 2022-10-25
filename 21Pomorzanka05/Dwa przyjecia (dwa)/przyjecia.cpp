#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const long long h1 = 1000000007, h2 = 694202137;

int n;
int wyn = 100000;

long long h4sh(bitset<201> b)
{
	long long h = 0;
	
	for (int i = 200; i >= 0; --i)
	{
		h = ((h << 1) + b[i] * h2) % h1;
	}
	
	return h;
}

vector<bitset<201>> nods;
map<int, bitset<201>> plecak;
bitset<201> sum, zero;


int main()
{
	scanf("%d", &n);
	
	int a, b;
	bitset<201> conns;
	conns = zero;
	
	plecak[h4sh(conns)] = conns; //pusty bitset
	
	nods.reserve(n);
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		
		conns = zero;
		
		for (int j = 0; j < a; ++j)
		{
			scanf("%d", &b);
			conns[b] = 1;
		}
		
		sum ^= conns;
		nods[h4sh(conns)] = conns;
	}
	
	bitset<201> pom;
	int h;
	
	for (bitset<201> item : nods)
	{
		for (auto i : plecak)
		{
			pom = i.ss ^ item;
			h = h4sh(pom);
			
			if(plecak[h] == zero)
			{
				plecak[h] = pom;
				wyn = min(wyn, (int)pom.count() + (int));
			}
		}
	}
	
	
	return 0;
}
