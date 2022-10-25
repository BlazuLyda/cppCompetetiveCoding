#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, z;
vector<pair<int, int>> sieve[500500];

// fractions
struct Frac {
	long long a, b;
	
	void norm() {
		long long at = a, bt = b, l;
		
		for (auto i : sieve[b]) {
			l = i.ss;
			
			while (l && !(a % i.ff)) {
				a /= i.ff;
				b /= i.ff;
				l--;
			}
		}
		
		a = at; b = bt;
	}
	
	void print() {
		norm();
		printf("%lld\%lld\n", &a, &b);
	}
};

bool operator>(Frac x, Frac y) {
	return x.a * y.b > x.b * y.a;
}

bool operator<(Frac x, Frac y) {
	return x.a * y.b < x.b * y.a;
}


// segment tree
struct Node {
	set<pair<pair<int, int>, pair<long long, Frac>>> seg;
	set<pair<pair<int, int>, pair<long long, Frac>>>::iterator it = seg.end();
};

const int R = 1 << 19;
Node tree[R << 1];

void update(int w, long long v) {
	pair<int, int> pom = tree[w].seg.begin()->ff;
	tree[w].seg.erase(tree[w].seg.begin());
	tree[w].seg.insert({pom, {v, {v, 1}}});
	
	w >>= 1;
	int s1, s2;
	pair<int, int> q1, q2;
	pair<long long, Frac> v1, v2, vw;
	
	while (w) {
		if (tree[w].it != tree[w].seg.end()) tree[w].seg.erase(tree[w].it);
		
		s1 = w<<1;
		s2 = w<<1|1;
		q1 = prev(tree[s1].seg.end())->ff;
		q2 = tree[s2].seg.begin()->ff;
		v1 = prev(tree[s1].seg.end())->ss;
		v2 = tree[s2].seg.begin()->ss;
		
		if (v1 < v2) {
			vw = {v1.ff + v2.ff, {v1.ff + v2.ff, q2.ss - q1.ff + 1}};
			vw.ss.norm();
			tree[w].it = tree[w].seg.insert({{q1.ff, q2.ss}, vw}).ff;
		} else {
			tree[w].it = tree[w].seg.end();
		}
		
		w >>= 1;
	}
}

Frac query(int w) {
	int sp, sa;
	pair<int, int> qc = tree[w].seg.begin()->ff, qa;
	pair<long long, Frac> vc = tree[w].seg.begin()->ss, va;
	sp = w;
	w >>= 1;
	
	while (w) {
		if (sp&1) continue;
		
		sa = sp|1;
		qa = tree[sa].seg.begin()->ff;
		va = tree[sa].seg.begin()->ss;
		
		if (va.ss > vc.ss) {
			qc = {qc.ff, qa.ss};
			vc = {vc.ff + va.ff, {vc.ff + va.ff, qc.ss - qc.ff + 1}};
			vc.ss.norm();
		} else {
			break;
		}
		
		sp = w;
		w >>= 1;
	}
	
	return vc.ss;
}

// preprocessing
void createSieve() {
	int tmp, l;
	
	for (int i = 2; i <= n; i++) {
		if (sieve[i].empty()) {
			for (int j = i; j <= n; j += i) {
				tmp = j;
				l = 0;
				
				while (!(tmp % i)) {
					tmp /= i;
					l++;
				}
				
				sieve[j].push_back({i, l});
			}
		}
	}
}

int main() {
	
	return 0;
}
