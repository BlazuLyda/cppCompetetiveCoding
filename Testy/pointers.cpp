#include <bits/stdc++.h>

using namespace std;

struct sample {
	int a, b;
};

int main()
{
	sample *bruh = new sample{1, 3};
	
	cout << bruh->a << "\n";
	
	bruh->b = 10;
	
	cout << bruh->b << "\n";
	
	return 0;
}
