#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct line {
	int x, v, y[2];
};

int n;
vector<pair<int, pair<int*, int*>>> scale;
vector<line> lines;

int main() {
	
	scanf("%d", &n);
	
	int x0, x1, y0, y1, pom;
	
	printf("\n");
	
	lines.reserve(n*2);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		
		pom = lines.size();
		lines.push_back({x0, 1, {1, 2}});
		lines.push_back({x1, -1, {3, 4}});
		
		scale.push_back({y0, {&lines[pom].y[0], &lines[pom+1].y[0]}});
		scale.push_back({y1, {&lines[pom].y[1], &lines[pom+1].y[1]}});
		
		printf("pom:%d\n", pom);
		lines[0].y[0] = pom;
		cout << &lines[0].y[0] << ": " << lines[0].y[0] << "\n";
		
		cout << &lines[pom].y[0] << ": " << lines[pom].y[0] << "\n";
		cout << &lines[pom].y[1] << ": " << lines[pom].y[1] << "\n";
		cout << &lines[pom+1].y[0] << ": " << lines[pom+1].y[0] << "\n";
		cout << &lines[pom+1].y[1] << ": " << lines[pom+1].y[1] << "\n";
	}
	
	printf("\n");
	
	lines[0].y[0] = 101;
	cout << &lines[0].y[0] << ": " << lines[0].y[0] << "\n";
	
	// skalowanie
	int last = 1000000, num = 0;
	sort(scale.begin(), scale.end());
	
	lines[0].y[0] = 102;
	cout << &lines[0].y[0] << ": " << lines[0].y[0] << "\n";
	
	for (auto i : scale) {
		if (i.ff != last) {
			num++;
			last = i.ff;
		}
		
		cout << i.ss.ff << ": " << *i.ss.ff << "\n";
		cout << i.ss.ss << ": " << *i.ss.ss << "\n";
		
		*i.ss.ff = num;
		*i.ss.ss = num;
	}
	
	return 0;
}
