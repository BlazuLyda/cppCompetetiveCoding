#include <bits/stdc++.h>

using namespace std;

long long NWD(long long x, long long y)
{
	if(x < y)
		swap(x, y);
		
	while(y != 0)
	{	
		x %= y;
		swap(x, y);
	}
	
	return x;
}

int main()
{
	cout << NWD(96, 60);
	
	return 0;
}