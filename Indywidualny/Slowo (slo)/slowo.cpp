#include <bits/stdc++.h>

using namespace std;

const long long mod = 100002173;
const long long p = 31;

int n, q;
long long pref[100005], pot[100005];
char str[100005];

int main()
{
	scanf("%d %d", &n, &q);
	
	scanf("%s", str);
	
	pot[0] = 1;
	
	for (int i = 1; i <= n; ++i)
	{
		pot[i] = (pot[i-1] * p) % mod;
		
		pref[i] = (pref[i-1] + ((long long)(str[i-1] - 'a') * pot[i])) % mod;
	}
	
	//zapytania
	int a, b, c;
	long long aHash, bHash;	
	
	while(q--)
	{
		scanf("%d %d %d", &a, &b, &c);
		
		if(b < a)
			swap(a, b);
			
		aHash = ((pref[a + c - 1] - pref[a - 1] + mod) * pot[b - a]) % mod;
		bHash = (pref[b + c - 1] - pref[b - 1] + mod) % mod;
		
		if(aHash == bHash)
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	
	return 0;
}