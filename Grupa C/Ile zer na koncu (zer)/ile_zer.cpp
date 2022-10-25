#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	
	int wyn = 0;
	
	wyn += n / 5;
	wyn += n / 25;
	wyn += n / 125;
	wyn += n / 625;
	wyn += n / 3125;
	wyn += n / 15625;
	
	printf("%d", wyn);
	
	return 0;
}