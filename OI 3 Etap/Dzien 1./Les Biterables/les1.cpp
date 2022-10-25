//autor: Błażej Łytkowski

#include <bits/stdc++.h>

using namespace std;

int n;
long long d;

int s, ls;
long long tab[500005], ltab[500005];

long long odp[500005];

int main()
{
	scanf("%d %lld", &n, &d);
	
	scanf("%d", &ls);
	
	for (int i = 0; i < ls; ++i)
	{
		scanf("%lld", &ltab[i]);
	}
	
	//wczytywanie pozostałych
	bool b;
	long long mini, cur;
	
	for (int j = 1; j < n; ++j)
	{
		scanf("%d", &s);
		
		b = 0;
		mini = LONG_LONG_MAX;
		cur = 0;
		
		for (int i = 0; i < s; ++i)
		{
			scanf("%lld", &tab[i]);
		}
		
		if(s > ls) //zamieniam ustawienia, bo nie ma to wpływu na rozwiązanie
		{
			b = 1;
			swap(s, ls);
			swap(tab, ltab);
		}
		
		for (int i = -s; i <= ls; ++i)
		{
			cur = 0;
			
			for (int k = 0; k < i; ++k) //stare na początku przedziału
			{
				cur += min(ltab[k], d-ltab[k]);
			}
			
			//printf("1:%lld\n", cur);
			
			for (int k = i; k < 0; ++k) //nowe na początku przedziału
			{
				cur += min(tab[k-i], d-tab[k-i]);
				
				//printf("tab[%d]:%lld\n", k-i, tab[k-i]);
			}
			
			//printf("2:%lld\n", cur);
			
			for (int k = max(0, i); k < min(i+s, ls); ++k) //wspólne
			{
				cur += abs(ltab[k] - tab[k-i]);
			}
			
			//printf("3:%lld\n", cur);
			
			for (int k = i+s; k < ls; ++k) //stare na końcu przedziału
			{
				cur += min(ltab[k], d-ltab[k]);
			}
			
			//printf("4:%lld\n", cur);
			
			for (int k = ls; k < i+s; ++k) //nowe na końcu przedziału
			{
				cur += min(tab[k-i], d-tab[k-i]);
			}
			
			//printf("5:%lld\n", cur);
			
			//printf("Ustawienie %d: %lld\n", i, cur);
			
			mini = min(mini, cur);
		}
		
		if(!b)
		{
			swap(s, ls);
			swap(tab, ltab);
		}
		
		odp[j] = mini;
	}
	
	for (int j = 1; j < n; j++)
	{
		printf("%lld\n", odp[j]);
	}
	
	return 0;
}