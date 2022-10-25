#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x, y;
}

int n, m;
vector<point> A, B;

point countCenter(vector<point> points, vector<long long> areas, int k) {
	long long xsum = 0, ysum = 0, asum = 0;
	
	for (int i = 0; i < k; i++) {
		xsum += points[i].x * areas[i];
		ysum += points[i].y * areas[i];
		asum += areas[i];
	}
	
	return point{xsum/asum, ysum/asum};
}

point triCenter(point a, point b, point c) {
	point d = {(a.x + b.x) / 2LL, (a.y + b.y) / 2LL};
	point e = {(a.x + c.x) / 2LL, (a.y + c.y) / 2LL};
	
	
}

long long area(point a, point b, point c) {
	b.x -= a.x; b.y -= a.y;
	c.x -= a.x; c.y -= a.y;
	long long res = a.x * b.y - a.y * b.x;
	
	return res > 0 ? res : -res;
}

int main() {
	float x, y;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%f %f", &x, &y);
		A.push_back({x*1000, y*1000});
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%f %f", &x, &y);
		B.push_back({x*1000, y*1000});
	}
	
	
	
	
	return 0;
}
