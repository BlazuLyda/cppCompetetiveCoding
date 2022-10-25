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
	
	//przykład wykorzystania funkcji rand
	cout << random(1, 10);
	
	return 0;
}