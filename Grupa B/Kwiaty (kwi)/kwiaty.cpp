#include <bits/stdc++.h>

using namespace std;

int n;
const int r = 131072;
int tree[2*r];

int query(int w)
{
	int res = 0;
	
	while(w)
	{
		res += tree[w];
		w >>= 1;
	}
	
	return res;
}

void update(int w, int p, int k, int x, int y) //(p, k) - przedział za który odpowiada wierzcholek w
{
	if(k < x || y < p)
		return;
		
	if(x <= p && k <= y)
	{
		++tree[w];
		return;
	}
	
	update(w*2, p, (p+k)/2, x, y);
	update(w*2+1, (p+k)/2+1, k, x, y);
}

int main()
{
	int L, R, q1, q2;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &L, &R);
		
		q1 = query(L+r);
		q2 = query(R+r);
		
		//printf("q1:%d q2:%d\n", q1, q2);
		
		tree[L+r] -= q1;
		tree[R+r] -= q2;
		
		if(R - L > 1)
			update(1, 0, r-1, L+1, R-1);
		
		printf("%d\n", q1 + q2);
	}
	
	return 0;
}