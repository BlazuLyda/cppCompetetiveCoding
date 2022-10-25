#include <bits/stdc++.h>

using namespace std;

int main()
{
	printf("250 500 2");
	
	printf("1 126\n");
	
	for (int i = 1; i < 250; i++)
	{
		printf("%d %d\n", i, i+1);
	}
	printf("250 1\n");
	
	for (int i = 1; i < 249; i++)
	{
		printf("%d %d\n", i, i+2);
	}
	printf("249 1\n");
	printf("250 2\n");
	
}