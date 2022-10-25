#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct line {
	long long a, b, c;
};

int n;
vector<pair<pair<int, int>, pair<int, int>>> points; // zbiór wszystkich miast, zawierają informacje o prostych do których należą i ich pozycję w nich
vector<int> cities[1000]; // vektor miast które leżą na konkretnej prostej
map<float, vector<int>> same; // proste równoległe do prostej
line lines[1000];

void createLine(int i) {
	long long x1, x2, y1, y2, a, b, c;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	
	a = (y2 - y1);
	b = (x1 - x2);
	c = a*x1 + b*y1;
	
	same[-((float)a/(float)b)].push_back(i);
	
	lines[i] = line(a, b, c);
}

bool cmp(long long a, long long b, long long c, long long d) {
	return a*d > c*b;
}

int main() {
	scanf("%d", &n);
	
	if (n == 1) {
		printf("0");
		exit(0);
	}
	
	for (int i = 0; i < n; i++) {
		createLine(i);
	}
	
	// Szukanie przecięć prostych
	int ptIdx = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
		}
	}
		
	return 0;
}
