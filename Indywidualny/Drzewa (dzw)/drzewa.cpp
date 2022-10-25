#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;

int pref[1000100];
vector<int> roz[1000100][2];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	string s;
	
	cin >> s;
	
	for (int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i-1] + (s[i-1] == 'J') - (s[i-1] == 'S');
	}
	
	int pom;
	bool wyn = 0;
	int a, b;
	
	roz[abs(pref[1])][pref[1] > 0].push_back(2);
	
	for (int i = 3; i <= n-2; ++i) //sosna = -1; jodla = 1
	{	
		pom = pref[n] - pref[i+1];
		
		for (auto j : roz[abs(pom)][pom > 0])
		{
			if((pref[i] - pref[j]) == pom)
			{
				a = j;
				b = i+1;
				wyn = 1;
				break;
			}
		}
		
		if(wyn)
			break;
			
		roz[pref[i-1]][pref[i-1] > 0].push_back(i);
	}
	
	if(wyn)
		printf("%d %d\n", a, b);
	else
		printf("BRAK\n");
	
	return 0;
}