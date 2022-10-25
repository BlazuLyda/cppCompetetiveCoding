#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v = {10};
	
	cout << (upper_bound(v.begin(), v.end(), 10) == v.end());
	
	
	return 0;
}
