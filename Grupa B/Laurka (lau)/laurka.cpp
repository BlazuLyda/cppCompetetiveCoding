#include <bits/stdc++.h>

using namespace std;

int n, q;
char s[100100];

// segment tree
struct Node {
	int lett[26];
	int siz;
	bool lazy = false;
	int op;
};

const int R = 1 << 17;
Node tree[R << 1];

void push(int w) {
	int s1 = w<<1;
	int s2 = w<<1|1;
	
	tree[w].lazy = false;
	tree[s1].lazy = true;
	tree[s2].lazy = true;
	tree[s1].op = tree[w].op;
	tree[s2].op = tree[w].op;
	
	int l = tree[s1].siz, idx, k, z;
	
	if (tree[w].op) {
		idx = 0; k = 26; z = 1;
	} else {
		idx = 25; k = -1; z = -1;
	}
	
	for (; idx != k; idx += z) {
		if (tree[w].lett[idx] <= l) {
			tree[s1].lett[idx] = tree[w].lett[idx];
			tree[s2].lett[idx] = 0;
			l -= tree[w].lett[idx];
		} else {
			tree[s1].lett[idx] = l;
			tree[s2].lett[idx] = tree[w].lett[idx] - l;
			
			for (idx += z; idx != k; idx += z) {
				tree[s2].lett[idx] = tree[w].lett[idx];
				tree[s1].lett[idx] = 0;
			}
			
			return;
		}
	}
}

queue<int> que;
stack<int> ups;
int col[26];

void collect(int w, int p, int k, int x, int y, int m) {
	if (y < p || k < x) return;
	if (x <= p && k <= y) {
		tree[w].lazy = true;
		tree[w].op = m;
		que.push(w);
		
		for (int i = 0; i < 26; i++) {
			col[i] += tree[w].lett[i];
			tree[w].lett[i] = 0;
		}
		
		return;
	}
	
	if (tree[w].lazy) push(w);
	int mid = (p + k) >> 1;
	ups.push(w);
	
	collect(w<<1, p, mid, x, y, m);
	collect(w<<1|1, mid+1, k, x, y, m);
}

void dist(int m) {
	int idx, k, z, w, l;
	
	if (m) {
		idx = 0; k = 26; z = 1;
	} else {
		idx = 25; k = -1; z = -1;
	}
	
	while (!que.empty()) {
		w = que.front();
		l = tree[w].siz;
		que.pop();
		
		for (; idx != k; idx += z) {
			if (l >= col[idx]) {
				tree[w].lett[idx] = col[idx];
				l -= col[idx];
				col[idx] = 0;
			} else {
				tree[w].lett[idx] = l;
				col[idx] -= l;
				break;
			}
		}
	}
	
	int s1, s2;
	
	while (!ups.empty()) {
		w = ups.top();
		ups.pop();
		
		s1 = w<<1;
		s2 = w<<1|1;
		
		for (int j = 0; j < 26; j++)
			tree[w].lett[j] = tree[s1].lett[j] + tree[s2].lett[j];
	}
}

int main() {
	scanf("%d %d", &n, &q);
	scanf("%s", s);
	
	for (int i = 0; i < n; i++) {
		tree[i + R].lett[s[i] - 'a']++;
		tree[i + R].siz = 1;
	}
	
	
	// tworzenie drzewa
	int s1, s2;
	
	for (int i = R-1; i > 0; i--) {
		s1 = i<<1;
		s2 = i<<1|1;
		tree[i].siz = tree[s1].siz + tree[s2].siz;
		
		for (int j = 0; j < 26; j++)
			tree[i].lett[j] = tree[s1].lett[j] + tree[s2].lett[j];
	}
	
	
	// zapytania
	int a, b, c;
	
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		
		collect(1, 0, R-1, a-1, b-1, c);
		dist(c);		
	}
	
	
	// pushowanie wszystkiego na dół
	for (int i = 1; i < R; i++) {
		if (tree[i].lazy) push(i);
	}
		
	// wypisanie wyniku
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (tree[i + R].lett[j]) {
				printf("%c", (char) (j + 'a'));
				break;
			}
		}
	}
	
	return 0;
}