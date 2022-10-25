#include <bits/stdc++.h>

using namespace std;

int random(int a, int b)
{
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[])
{
	int seed = atoi(argv[1]);
	
	seed *= seed; 
	
	srand(seed);
	
	int n = 2;
	
	printf("%d\n", n);
	
	for (int i = 0; i < n; i++)
	{
		printf("1000000 %d\n", random(0, 10000));
	}
	
	return 0;
}