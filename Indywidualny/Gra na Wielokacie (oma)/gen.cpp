#include <bits/stdc++.h>

using namespace std;

bool tab[1010][2] = {{1, 0}, {0, 1}, {0, 1}};
//tab[i][0] == 1 ---> Gracz ma strategię wymuszającą parzystą liczbę ruchów na przedziale długości i
//tab[i][1] == 1 ---> Gracz ma strategię wymuszającą nieparzystą liczbę ruchów na przedziale długości i

int main()
{	
	int n;
	
	for (int i = 3; i <= 1000; ++i)
	{	
		if(tab[i-2][0] && !tab[i-2][1])
			tab[i][1] = 1;
			
		else if(!tab[i-2][0] && tab[i-2][1])
			tab[i][0] = 1;
		
		n = i - 3;	
		
		for (int j = 0; j <= n/2; ++j)
		{
			if((tab[j][0] && tab[j][1]) || (tab[n-j][0] && tab[n-j][1]))
				continue;
			
			if(tab[j][0] == tab[n-j][0])
				tab[i][1] = 1;
			else
				tab[i][0] = 1;	
		}
	}
		
	for(auto i : tab)
	{	
		printf("{%d, %d}, ", i[0], i[1]);
	}
	
	return 0;
}
