#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v[] = {1, 2, 3, 4};
	
	//int * itr = v;
	
	cout << &v[0] << "\n";
	cout << &v[1] << "\n";
	cout << &v[2] << "\n";
	cout << &v[3] << "\n";
	//cout << * (&v[0] + sizeof(int)) << "\n";
	
	/*
	for (int i = 0; i < 4; i++) {
		printf("%d\n", *itr);
		itr += sizeof(int);
	}
	*/
	
	
	return 0;
}
