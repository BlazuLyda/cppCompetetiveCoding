#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	vector<int> w = {v.begin(), v.end()-3};
	
	for (auto i : w) printf("%d ", i);
	
	return 0;
}
