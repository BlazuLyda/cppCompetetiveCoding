#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> s = {1, 2, 4, 5, 7};
	
	//auto it = s.find(7);
	
	cout << distance(s.begin(), s.find(7));
	
	return 0;
}
