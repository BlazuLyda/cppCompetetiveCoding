#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
set<pair<int,int>> s;

int main()
{
	scanf("%d", &n);
	
	s.insert({-1, -1});
	s.insert({INT_MAX, -1});
	
	int a, dep, res = 0;
	set<pair<int,int>>::iterator up;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		
		up = s.upper_bound({a, 0});
		
		dep = max((*up).ss, (*prev(up)).ss) + 1;
		
		s.insert({a, dep});
		
		res = max(res, dep);
	}
	
	printf("%d\n", res);
	
	return 0;
}