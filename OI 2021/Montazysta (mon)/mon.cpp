#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct Activity {
	long long time, due;
	int idx;
	
	bool operator<(Activity sc) const {
		return due < sc.due;
	}
};


int n;
vector<Activity> mov; // deadline, czas
priority_queue<pair<long long, int>> que; // czas, idx
vector<int> sor;
vector<int> picked;

bool cmp(int a, int b) {
	return mov[a].due < mov[b].due; 
}

int main() {
	// Scan input
	scanf("%d", &n);
	mov.resize(n);
	sor.resize(n);
	
	long long a, b;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		mov[i] = {a, b, i};
		sor[i] = i;
	}
	
	// Solve
	sort(sor.begin(), sor.end(), cmp);
	
	long long t = 0, l = 0;
	Activity *act;
	
	for (auto i : sor) {
		act = &mov[i];
		
		t += act->due - l;
		l = act->due;
		
		que.push({act->time, act->idx});
		t -= act->time;
		
		if (t < 0) {
			t += que.top().ff;
			que.pop();
		}
	}
	
	// Print result
	printf("%lu\n", que.size());
	
	picked.reserve(que.size());
	
	while (!que.empty()) {
		picked.push_back(que.top().ss);
		que.pop();
	}
	
	sort(picked.begin(), picked.end(), cmp);
	
	long long ts = 1;
	
	for (auto i : picked) {
		printf("%d %lld\n", i+1, ts);
		
		ts += mov[i].time;
	}
	
	return 0;
}
