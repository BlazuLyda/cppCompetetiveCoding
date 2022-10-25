#include <bits/stdc++.h>

using namespace std;

struct b_int {
	vector<int> num;
	
	void print() {
		if (!num.size()) num.push_back(0);
		for (auto i = num.end()-1; i >= num.begin(); i--) {
			printf("%d", *i);
		}
		printf("\n");
	}
};

b_int operator+(b_int a, b_int b) {
	if (b.num.size() > a.num.size()) {
		b.num.push_back(0);
		a.num.resize(b.num.size());
	} else {
		a.num.push_back(0);
		b.num.resize(a.num.size());
	}
	
	for (int i = 0; i < (int)a.num.size() - 1; i++) {
		a.num[i] += b.num[i];
		a.num[i+1] += a.num[i] / 10;
		a.num[i] %= 10;
	}
	
	while (a.num.back() == 0) a.num.pop_back();
	return a;
}

int n;

int main() {
	scanf("%d", &n);
	
	b_int add = {{1}}, wyn = {};
	int s;
	
	if (n % 3 == 0)			s = 2;
	else if (n % 3 == 1)	s = 1;
	else 					s = 0;
	
	
	for (int i = 0; i < n; i++) {
		if (s) wyn = wyn + add;
		
		s++;
		s %= 3;
		
		add = add + add;
	}
	
	wyn.print();
		
	return 0;
}
