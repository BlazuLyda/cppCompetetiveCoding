#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m, k;
const int R = 131072;

long long tree[2 * R];

void update(int w, long long val)
{
	while(w)
	{
		tree[w] = max(tree[w], val);
		
		w >>= 1;
	}
}

long long query(int w, int p, int k, int x, int y)
{
	if(y < p || k < x)
		return 0;
	
	if(x <= p && k <= y)
		return tree[w];
		
	return max(query(w*2, p, (p+k)/2, x, y), query(w*2+1, (p+k)/2+1, k, x, y));
}

vector<pair<pair<int,int>, long long>> stops;
vector<pair<int, int>> xcords;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	stops.resize(k);
	xcords.resize(k);
	
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %lld", &stops[i].ff.ss, &stops[i].ff.ff, &stops[i].ss);
		
		xcords[i] = {stops[i].ff.ss, i};
	}
	
	
	//skalowanie
	sort(xcords.begin(), xcords.end());
	
	int num = 1;
	
	stops[xcords[0].ss].ff.ss = num;
	
	for (int i = 1; i < k; i++)
	{
		if(xcords[i].ff != xcords[i-1].ff)
			++num;
			
		stops[xcords[i].ss].ff.ss = num;
	}
	
	//szukanie wyniku
	sort(stops.begin(), stops.end());
	
	long long cur, wyn = 0;
	
	for (int i = 0; i < k; i++)
	{
		cur = query(1, 0, R-1, 0, stops[i].ff.ss) + stops[i].ss;
		
		//printf("x:%d y:%d osoby:%lld wynik:%lld\n", stops[i].ff.ss, stops[i].ff.ff, stops[i].ss, cur);
		
		update(stops[i].ff.ss + R, cur);
		
		wyn = max(cur, wyn);
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}