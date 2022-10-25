#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
stack<pair<int,int>> vis; //wysokość, liczba
int res;

int main() {
	scanf("%d", &n);
	
	int a, pushNum;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		
		while (!vis.empty() && vis.top().ff < a) {
			res += vis.top().ss;
			vis.pop();
		}
		
		if (!vis.empty() && vis.top().ff == a) {
			pushNum = vis.top().ss + 1;
			res += vis.top().ss;
			vis.pop();
		} else {
			pushNum = 1;
		}
		
		if (!vis.empty()) {
			res ++;
		}
		vis.push({a, pushNum});
	}
	
	printf("%d", res);
	
	return 0;
}
