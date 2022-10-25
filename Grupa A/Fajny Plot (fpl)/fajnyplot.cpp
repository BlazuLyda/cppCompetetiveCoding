#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const long long mod = 1000000007;

int n;
long long a[100100], h[100100];
long long L[100100], R[100100];
long long pref[100100];
deque<pair<long long, int>> que;

int qquery(long long h)
{
	while(que.back().ff >= h)
		que.pop_back();
		
	return que.back().ss;
}

int qquery1(long long h)
{
	while(que.back().ff > h)
		que.pop_back();
		
	return que.back().ss;
}

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &h[i]);
	}
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		
		pref[i] = (pref[i-1] + a[i]) % mod;
	}
	
	//first shorter on the right and left
	que.push_front({0, 0});
	
	for (int i = 1; i <= n; ++i)
	{
		L[i] = qquery(h[i]);
		
		que.push_back({h[i], i});
	}
	
	que.clear();
	
	que.push_front({0, n+1});
	
	for (int i = n; i > 0; --i)
	{
		R[i] = qquery1(h[i]);
		
		que.push_back({h[i], i});
	}
	
	//counting the cool rectangles
	long long res = 0;
	long long wid, a1, a2, add; 
	
	for (int i = 1; i <= n; ++i)
	{	
		wid = (pref[R[i]-1] - pref[L[i]] + mod) % mod;
		a2 = (pref[R[i]-1] - pref[i] + mod) % mod;
		a1 = (pref[i-1] - pref[L[i]] + mod) % mod;
		
		add = (((wid * (wid+1ll) / 2ll) % mod) - ((a1 * (a1+1ll) / 2ll) % mod) - ((a2 * (a2+1ll) / 2ll) % mod) + (mod * 2ll)) % mod;
		
		add = (((h[i] * (h[i]+1ll) / 2ll) % mod) * add) % mod;
		
		res = (res + add) % mod;
		
		//printf("%d..... wid:%lld a1:%lld a2:%lld add:%lld\n", i, wid, a1, a2, add);
	}
	
	printf("%lld\n", res);
	
	return 0;
}