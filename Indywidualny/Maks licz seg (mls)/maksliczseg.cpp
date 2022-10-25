#include <bits/stdc++.h>

using namespace std;

struct point
{
	long long x, y;
	
	void read()
	{ 
		scanf("%lld %lld", &x, &y);
	}
};

bool cmp(point a, point b)
{
	return (long long)(a.x * b.y) > (long long)(b.x * a.y);
}

int n;
vector<point> v;

void printSlopes()
{
	printf("Slopes:\n");
	
	for (auto i : v)
	{
		printf("(%lld %lld) --> %f\n", i.x, i.y, (float)((float)i.y / (float)i.x));
	}
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	
	point a, b;
	
	for (int i = 0; i < n; i++)
	{
		a.read();
		b.read();
		
		if((b.x < a.x) || ((a.x == b.x) && (b.y < a.y)))
			swap(a, b);
		
		b.x -= a.x;
		b.y -= a.y;
		
		v.push_back(b);
	}
	
	//printSlopes();
	
	sort(v.begin(), v.end(), cmp);
	
	long long mof = 0, cnt = 1, wyn;
	
	for (int i = 1; i < (int)v.size(); ++i)
	{
		if((v[i].x * v[i-1].y) != (v[i-1].x * v[i].y))
		{
			mof += cnt * (cnt-1ll);
			
			cnt = 1ll;
		}
		else
			cnt += 1ll;
	}
	
	mof += cnt * (cnt-1ll);
	
	wyn = (n * (n+1ll) - mof) / 2ll + 1ll;
	
	printf("%lld\n", wyn);
	
	return 0;
}