#include <bits/stdc++.h>

using namespace std;

int n, q;

// segment tree
struct Node {
	double val;
	bool lazy = false;
	double push;
};

const int R = 262144;
Node tree[R<<1];

void push(int w) {
	if (!tree[w].lazy || w >= R) return;
	
	int s1 = w<<1;
	int s2 = w<<1|1;
	
	tree[w].lazy = false;
	tree[s1].lazy = true;
	tree[s2].lazy = true;
	
	tree[s1].push = tree[w].push;
	tree[s2].push = tree[w].push;
	
	tree[s1].val = tree[w].val / 2;
	tree[s2].val = tree[w].val / 2;
}

//queue<int> que;
//stack<int> ups;

double collect(int w, int p, int k, int x, int y) {
	if (y < p || k < x) return 0;
	if (x <= p && k <= y) {
		//~ printf("(%d;%d)\n", p+1, k+1);
		//~ printf("sum:%lf\n", tree[w].val);
		//~ printf("avg:%lf\n\n", tree[w].val / tree[w].siz);
		//~ printf("X %d %d\n", p+1, k+1);
		
		// que.push(w);
		return tree[w].val;
	}
	
	// ups.push(w);
	push(w);
	int mid = (p + k) >> 1;
	
	return collect(w<<1, p, mid, x, y) + collect(w<<1|1, mid+1, k, x, y);
}

void update(int w, int p, int k, int x, int y, double v) {
	if (y < p || k < x) return;
	if (x <= p && k <= y) {
		tree[w].val = (k-p+1) * v;
		tree[w].lazy = true;
		tree[w].push = v;
		return;
	}
	
	int mid = (p + k) >> 1;
	update(w<<1, p, mid, x, y, v);
	update(w<<1|1, mid+1, k, x, y, v);
	tree[w].val = tree[w<<1].val + tree[w<<1|1].val;
}

//~ void update1(double v) {
	//~ int w;
	//~ while (!que.empty()) {
		//~ w = que.front();
		//~ que.pop();
		
		//~ tree[w].val = tree[w].siz * v;
		//~ tree[w].lazy = true;
		//~ tree[w].push = v;
	//~ }
	
	//~ while (!ups.empty()) {
		//~ w = ups.top();
		//~ ups.pop();
		
		//~ tree[w].val = tree[w<<1].val + tree[w<<1|1].val;
	//~ }
//~ }

stack<int> anc;

double query(int w) {
	int w1 = w>>1;
	while (w1) {
		anc.push(w1);
		w1 >>= 1;
	}
	
	int w2;
	while (!anc.empty()) {
		w2 = anc.top();
		anc.pop();
		push(w2);
	}
	
	return tree[w].val;
}

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		scanf("%lf", &tree[i+R].val);
	}
	
	for (int i = R-1; i > 0; i--) {
		tree[i].val = tree[i<<1].val + tree[i<<1|1].val;
	}
	
	int x, y;
	char c;
	double sum, odp;
	
	while (q--) {
		scanf(" %c", &c);
		
		if (c == 'Z') {
			scanf("%d %d", &x, &y);
			sum = collect(1, 0, R-1, x-1, y-1);
			
			// printf("Z %d %d\n", x, y);
			
			//~ printf("\t--zmiana--\n");
			//~ printf("(%d;%d)\n", x, y);
			//~ printf("sum:%lf\n", sum);
			//~ printf("avg:%lf\n\n", sum / ((double) y - x + 1.0));
			
			// update(sum / ((double) y - x + 1.0));
			update(1, 0, R-1, x-1, y-1, sum / (y-x+1));
		} else {
			scanf("%d", &x);
			odp = query(x-1+R);
			printf("%lf\n", odp);
		}
	}
	
	return 0;
}