#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

struct comp {
	double a, b;
};

comp operator*(comp x, comp y) {
	return {x.a*y.a - x.b*x.b, x.a*y.b + x.b*y.a};
}

comp operator+(comp x, comp y) {
	return {x.a+y.a, x.b+y.b};
}

comp operator-(comp x, comp y) {
	return {x.a-y.a, x.b-y.b};
}

vector<comp> fft(vector<int> w, vector<comp> pts) {
	if (w.size() == 1) return {{(double)w[0], 0}};
	
	int s = pts.size() >> 1;
	vector<int> even, odd;
	vector<comp> half;
	
	for (int i = 0; i < (int)w.size(); i += 2) {
		even.push_back(w[i]);
		odd.push_back(w[i+1]);
	}
	
	for (int i = 0; i < (int)pts.size(); i += 2) {
		half.push_back(pts[i]);
	}
	
	vector<comp> a = fft(even, half);
	vector<comp> b = fft(odd, half);
	vector<comp> res(s << 1);
	
	for (int i = 0; i < (int)half.size(); i++) {
		res[i] = a[i] + pts[i] * b[i];
		res[i+s] = a[i] + pts[i+s] * b[i];
	}
	
	return res;
}

int main() {
	int n, q = 1;
	vector<int> a, b;
	vector<comp> pa, pb;
	
	scanf("%d", &n);
	
	while (q < n) q <<= 1;
	
	a.resize(q);
	b.resize(q);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	
	
	
	return 0;
}
