#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int a, b, c, d;
long long res;

deque<pair<int,int>> l1, l2, r1, r2;

void clear_outdated(int y)
{
	while(!l1.empty() && (l1.front().ss <= (y - d)))
		l1.pop_front();
			
	while(!r1.empty() && (r1.front().ss <= (y - d)))
		r1.pop_front();
		
	while(!l2.empty() && (l2.front().ss <= (y - c)))
		l2.pop_front();
		
	while(!r2.empty() && (r2.front().ss <= (y - c)))
		r2.pop_front();
}

void push_new(int x, int l, int y)
{
	while(!l1.empty() && (l1.back().ff <= x))
		l1.pop_back();
		
	while(!r1.empty() && (r1.back().ff >= (x+l)))
		r1.pop_back();
		
	while(!l2.empty() && (l2.back().ff <= x))
		l2.pop_back();
		
	while(!r2.empty() && (r2.back().ff >= (x+l)))
		r2.pop_back();
		
	l1.push_back({x, y});
	r1.push_back({x+l, y});
	l2.push_back({x, y});
	r2.push_back({x+l, y});
}

int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	int x, l;
	int p1, p2, k1, k2; //(p1, k1) - CxD;  (p2, k2) - DxC;
	
	l1.push_front({a+1, 0});
	l2.push_front({a+1, 0});
	r1.push_front({1, 0});
	r2.push_front({1, 0});
	
	for (int i = 1; i <= b; ++i)
	{
		scanf("%d %d", &x, &l);
		
		clear_outdated(i); 
		
		push_new(x, l, i);
		
		p1 = l1.front().ff;
		k1 = r1.front().ff;
		p2 = l2.front().ff;
		k2 = r2.front().ff;
		
		res += (long long)(max(0LL, k1 - p1 - c + 1LL));
		res += (long long)(max(0LL, k2 - p2 - d + 1LL));
	}
	
	if(c == d)
		printf("%lld\n", res/2LL);
	else
		printf("%lld\n", res);
	
	return 0;
}