#include <bits/stdc++.h>

using namespace std;

int t, n;

bool tab[1010][2] = {{1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}, {0, 1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
//tab[i][0] == 1 ---> Gracz ma strategię wymuszającą parzystą liczbę ruchów na przedziale długości i
//tab[i][1] == 1 ---> Gracz ma strategię wymuszającą nieparzystą liczbę ruchów na przedziale długości i

int main()
{	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &n);
		
		if(tab[n-3][1] == 1)
			printf("Drugi\n");
		else
			printf("Pierwszy\n");
	}
	
	return 0;
}
