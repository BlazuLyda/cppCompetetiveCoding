#include <bits/stdc++.h>

using namespace std;

unsigned long long D[60] = {0, 1, 3};
unsigned long long pref[60] = {0, 1, 4};

int main()
{
	for (unsigned long long i = 1; i <= 56; ++i)
	{
		D[i] = (1LLU << (i-1LLU)) + pref[i-1];
		pref[i] = pref[i-1] + D[i];
	}
	
	printf("D[57] = {");
	for (int i = 0; i < 57; ++i)
	{
		printf("%lld, ", D[i]);
	}
	printf("\n");
	
	printf("pref[57] = {");
	for (int i = 0; i < 57; ++i)
	{
		printf("%lld, ", pref[i]);
	}
	printf("\n");
	
	
	return 0;
}
