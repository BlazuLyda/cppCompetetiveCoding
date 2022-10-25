#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct point
{
	int x, y;
};

int k;

point obj[100][2]; //obj[0] and obj[1] are points

vector<pair<int, pair<int,int>>> Yscale, Xscale; //<value <idx, ff or ss>>

priority_queue<pair<pair<int,int>, pair<int,int>>> que; //<<cost, up or left> <x, y>>

bool wall[1000][1000];
int cost[1000][1000][2];

int main()
{
	//Input
	scanf("%d %d", &obj[0][0].x, &obj[0][0].y);
	scanf("%d %d", &obj[1][0].x, &obj[1][0].y);
	
	Xscale.push_back({obj[0][0].x, {0, 0}});
	Xscale.push_back({obj[1][0].x, {1, 0}});
	Yscale.push_back({obj[0][0].y, {0, 0}});
	Yscale.push_back({obj[1][0].y, {1, 0}});
	
	scanf("%d", &k);
	
	for (int i = 2; i < k+2; ++i)
	{
		scanf("%d %d %d %d", &obj[i][0].x, &obj[i][0].y, &obj[i][1].x, &obj[i][1].y);
		
		Xscale.push_back({obj[i][0].x, {i, 0}});
		Xscale.push_back({obj[i][1].x, {i, 1}});
		Yscale.push_back({obj[i][0].y, {i, 0}});
		Yscale.push_back({obj[i][1].y, {i, 1}});
	}
	
	
	//Scaling
	sort(Xscale.begin(), Xscale.end());
	sort(Yscale.begin(), Yscale.end());
	
	int x = 1, y = 1;
	
	obj[Xscale[0].ss.ff][Xscale[0].ss.ss].x = x;
	
	for (int i = 1; i < (int)Xscale.size(); ++i)
	{
		x += min(Xscale[i].ff - Xscale[i-1].ff, 2);
		
		obj[Xscale[i].ss.ff][Xscale[i].ss.ss].x = x;
	}
	
	int xm = x + 1;
	
	obj[Yscale[0].ss.ff][Yscale[0].ss.ss].y = y;
	
	for (int i = 1; i < (int)Yscale.size(); ++i)
	{
		y += min(Yscale[i].ff - Yscale[i-1].ff, 2);
		
		obj[Yscale[i].ss.ff][Yscale[i].ss.ss].y = y;
	}
	
	int ym = y + 1;
	
	//Filling the plane
	int x1, x2, y1, y2;
	
	for (int i = 2; i < k+2; ++i)
	{
		if(obj[i][0].x > obj[i][1].x || obj[i][0].y > obj[i][1].y)
			swap(obj[i][0], obj[i][1]);
			
		x1 = obj[i][0].x; x2 = obj[i][1].x;
		y1 = obj[i][0].y; y2 = obj[i][1].y;
		
		for (int j = x1; j <= x2; ++j)
		{
			for (int k = y1; k <= y2; ++k)
			{
				wall[j][k] = 1;
			}
		}	
	}
	
	//debug - print the scaled table
	/*
	for (int j = ym; j >= 0; --j)
	{
		for (int i = 0; i <= xm; ++i)
		{
			if(obj[0][0].x == i && obj[0][0].y == j)
				printf("A");
			else if(obj[1][0].x == i && obj[1][0].y == j)
				printf("B");
			else if(wall[i][j])
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	*/
	
	//Dijkstra
	int c, d;
		
	que.push({{-1, 0}, {obj[0][0].x, obj[0][0].y}});
	que.push({{-1, 1}, {obj[0][0].x, obj[0][0].y}});
	
	while(!que.empty())
	{
		c = -que.top().ff.ff;
		d = que.top().ff.ss;
		
		x = que.top().ss.ff;
		y = que.top().ss.ss;
		
		que.pop();
		
		if(cost[x][y][d])
			continue;
			
		//printf("x:%d y:%d c:%d direction:%d wall:%d\n", x, y, c, d, wall[x][y]);
			
		cost[x][y][d] = c;
		
		if(x < xm && !wall[x+1][y]) 
			que.push({{-(c + (d == 1)), 0}, {x+1, y}});
			
		if(y < ym && !wall[x][y+1]) 
			que.push({{-(c + (d == 0)), 1}, {x, y+1}});
			
		if(x > 0 && !wall[x-1][y]) 
			que.push({{-(c + (d == 1)), 0}, {x-1, y}});
			
		if(y > 0 && !wall[x][y-1]) 
			que.push({{-(c + (d == 0)), 1}, {x, y-1}});
	}
	
	if(cost[obj[1][0].x][obj[1][0].y][0] == 0 && cost[obj[1][0].x][obj[1][0].y][1] == 0)
		printf("BRAK\n");
	else if(cost[obj[1][0].x][obj[1][0].y][0] == 0 || cost[obj[1][0].x][obj[1][0].y][1] == 0)
		printf("%d\n", max(cost[obj[1][0].x][obj[1][0].y][0], cost[obj[1][0].x][obj[1][0].y][1]));
	else
		printf("%d\n", min(cost[obj[1][0].x][obj[1][0].y][0], cost[obj[1][0].x][obj[1][0].y][1]));
	
	return 0;
}
