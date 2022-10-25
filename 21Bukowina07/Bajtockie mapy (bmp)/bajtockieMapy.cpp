#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const long long R = 2147483648;
int n, k;

long long pos[100100];

long long pot2[40];
vector<int> zero;

struct TreeNode {
	long long sons[2];
	vector<int> vis;
};

priority_queue<pair<pair<

unordered_map<long long, int> nodeIdx;
vector<TreeNode> tree;
int treeIdx;

bool cmpGreater(int a, int b) {
	return a > b;
}

void update(long long w, int v) {
	int son = ++treeIdx;
	int o;
	tree.push_back({0, 0}, zero);
	tree[son].vis[0] = v;
	w >>= 1LL;
	
	while (w) { //dobudowywanie nowych wierzchołków
		if (!nodeIdx[w]) {
			nodeIdx[w] = ++treeIdx;
			o = treeIdx;
			tree.push_back({0, 0}, zero);
			
			tree[o].sons[w % 2LL] = son;
			tree[o].vis[0] = v;
			
			son = o;
			w >>= 1LL;
		}
		else {
			o = nodeIdx[w];
			tree[o].sons[w % 2LL] = son;
			
			if (v > tree[o].vis[k-1]) {
				tree[o].vis[k-1] = v;
				sort(tree[o].vis.begin(), tree[o].vis.end(), cmpGreater);
			}
			
			w >>= 1LL;
			break;
		}
	}
	
	while (w) { //updatowanie starych wierzchołków
		o = nodeIdx[w];
		
		if (v > tree[o].vis[k-1]) {
			tree[o].vis[k-1] = v;
			sort(tree[o].vis.begin(), tree[o].vis.end(), cmpGreater);
		}
			
		w >>= 1LL;
	}
}

vector<int> query(int w, long long p, long long k, long long x, long long y) {
	if(y < p || k < x)
		return zero;
	
	if(x <= p && k <= y)
		return vis;
		
	vector<int> a = {}, b = {};
	
	if (tree[w].sons[0])
		a = query(tree[w].sons[0], p, (p+k)/2LL, x, y);
		
	if (tree[w].sons[1])
		b = query(tree[w].sons[1], (p+k)/2LL+1LL, k, x, y);
		
	a.insert(a.end(), b.begin(), b.end());
	sort(a.begin(), a.end(), cmpGreater);
	while ((int)a.size() > k)	a.pop_back();
	
	return a;
}

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) { zero.push_back(0) };
	pot2[0] = 1;
	for (int i = 1; i < 40; i++) { pot2[i] = pot2[i-1] << 1LL; }
	nodeIdx[1] = 1;
	treeIdx = 1;
	tree.push_back({}, zero); //0
	tree.push_back({}, zero); //1 - root
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &pos[i]);
		pos[i] += 100000000LL;
		
		update(pos[i] + R, i);
	}
	
	priority
	
	return 0;
}
