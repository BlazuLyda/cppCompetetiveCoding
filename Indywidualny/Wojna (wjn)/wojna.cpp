#include <bits/stdc++.h>

using namespace std;

int n, d, wyn;
char pos[1010];

int main()
{
	scanf("%d %d", &n, &d);
	
	scanf("%s", pos);
	
	int a, b;
	
	for (int i = 0; i < d; ++i)
	{
		scanf("%d %d", &a, &b);
		
		if(pos[a-1] == 'J' && pos[b-1] == 'J')
			++wyn;
	}
	
	printf("%d", wyn);
	
	return 0;
}
