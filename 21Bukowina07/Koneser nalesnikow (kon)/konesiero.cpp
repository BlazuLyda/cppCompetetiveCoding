#include <bits/stdc++.h>
#include "konlib.h"
#define ff first
#define ss second

using namespace std;

struct range {
	pair<int, int> maxX, maxL, maxR;
};

int n;

range findRange(int p, int k, int h) {
	range R;
	
	if (p == k) {
		R.maxL = {p, p};
		R.maxR = {p, p};
		R.maxX = {p, p};
		
		//for (int i = 0; i < h; i++) printf("  ");
		//printf("p:%d k:%d | ", p, k);
		//printf("maxL:{%d, %d} maxR:{%d, %d} maxX:{%d, %d}\n", R.maxL.ff, R.maxL.ss, R.maxR.ff, R.maxR.ss, R.maxX.ff, R.maxX.ss);
		return R;
	}
	
	if (p+1 == k) {
		if (lepszy(p, p, p, k)) R.maxL = {p, p};
		else R.maxL = {p, k};
		
		if (lepszy(k, k, p, k)) R.maxR = {k, k};
		else R.maxR = {p, k};
		
		if (lepszy(R.maxL.ff, R.maxL.ss, R.maxR.ff, R.maxR.ss)) R.maxX = {R.maxL.ff, R.maxL.ss};
		else R.maxX = {R.maxR.ff, R.maxR.ss};
		
		//for (int i = 0; i < h; i++) printf("  ");
		//printf("p:%d k:%d | ", p, k);
		//printf("maxL:{%d, %d} maxR:{%d, %d} maxX:{%d, %d}\n", R.maxL.ff, R.maxL.ss, R.maxR.ff, R.maxR.ss, R.maxX.ff, R.maxX.ss);
		return R;
	}
	
	range A = findRange(p, (p + k) / 2, h+1);
	range B = findRange((p + k) / 2 + 1, k, h+1);
	
	//maxL
	if (lepszy(p, A.maxL.ss, p, B.maxL.ss)) R.maxL = {p, A.maxL.ss};
	else R.maxL = {p, B.maxL.ss};
	
	//maxR
	if (lepszy(B.maxR.ff, k, A.maxR.ff, k)) R.maxR = {B.maxR.ff, k};
	else R.maxR = {A.maxR.ff, k};
	
	//maxX
	if (lepszy(A.maxX.ff, A.maxX.ss, B.maxX.ff, B.maxX.ss)) R.maxX= {A.maxX.ff, A.maxX.ss};
	else R.maxX = {B.maxX.ff, B.maxX.ss};
	if (lepszy(A.maxR.ff, B.maxL.ss, R.maxX.ff, R.maxX.ss)) R.maxX= {A.maxR.ff, B.maxL.ss};
	
	//for (int i = 0; i < h; i++) printf("  ");
	//printf("p:%d k:%d | ", p, k);
	//printf("maxL:{%d, %d} maxR:{%d, %d} maxX:{%d, %d}\n", R.maxL.ff, R.maxL.ss, R.maxR.ff, R.maxR.ss, R.maxX.ff, R.maxX.ss);
	return R;
}



int main() {
	n = nalesniki();
	
	range res = findRange(1, n, 1);
	
	odpowiedz(res.maxX.ff, res.maxX.ss);

	return 0;  
}