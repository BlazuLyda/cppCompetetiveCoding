#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int t, n, m;
int tab[3003][3003];
int hei[3003], L[3003], R[3003], diff[3003], str[3003], fin[3003];
vector<int> vec1[3003][2], vec2[3003][2];
int p, d;

int main()
{
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &tab[i][j]);
			}
		}
		
		for (int j = 1; j <= m; ++j) //ustawianie wstepnych wartosci w pionie
		{
			tab[0][j] = 2*tab[1][j] - tab[2][j];
			hei[j] = 0;
			diff[j] = tab[1][j] - tab[0][j];
		}
		
		for (int i = 1; i <= n; ++i) //ustawianie wstepnych wartosci w poziomie
		{
			tab[i][0] = 2*tab[i][1] - tab[i][2];
			tab[i][m+1] = 2*tab[i][m] - tab[i][m-1];
		}
		
		
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j) //sprawdzanie ciągów arytmetycznych w pionie
			{
				if((tab[i][j] - tab[i-1][j]) == diff[j])
					++hei[j];
				else
				{
					hei[j] = 2;
					diff[j] = tab[i][j] - tab[i-1][j];
				}
			}
			
			//sprawdzanie ciągów arytmetycznych w poziomie
			p = 1;
			d = tab[i][2] - tab[i][1];
			
			for (int j = 1; j <= m; ++j) //w prawo (początki)
			{
				vec1[j][0].clear();
				vec1[j][1].clear();
				
				if((tab[i][j] - tab[i][j-1]) != d)
				{
					p = j - 1;
					d = tab[i][j] - tab[i][j-1];
					
					for (int i = 0; i < _; i++)
					{
						
					}
				}
				
				vec1[j].push_back({p, 0});
			}
		}
		
		
	}
	
	
	return 0;
}