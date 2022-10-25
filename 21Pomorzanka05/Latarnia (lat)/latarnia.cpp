#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;

bool visit[603];

struct win
{
	int x1, x2, y1, y2;
	
	void read()
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}
	
	win reflect()
	{
		win result;
		
		result.x1 = x1 * 2 - 1000;
		result.y1 = y1 * 2 - 1000;
		result.x2 = x2 * 2 - 1000;
		result.y2 = y2 * 2 - 1000;
		
		return result;
	}
};

struct point
{
	int idx, w;
};

win makeWin(int x1, int y1, int x2, int y2)
{
	win result;
		
	result.x1 = x1;
	result.y1 = y1;
	result.x2 = x2;
	result.y2 = y2;
	
	return result;
}

vector<win> wall[2];

const int R = 2048;

vector<point> tree[2][2 * R][2 * R];
vector<int> Widx;

vector<int> findY(int w, int p, int k, int x, int y)
{	
	vector<int> result;
	
	if(k <= x || y <= p)
		return result;
	
	if(p < x && y < k)
	{
		result.push_back(w);
		return result;
	}
	
	vector<int> pom1 = findY(w*2, p, (p+k)/2, x, y);
	vector<int> pom2 = findY(w*2+1, (p+k)/2+1, k, x, y);
	
	result.reserve( pom1.size() + pom2.size() );
	result.insert( result.end(), pom1.begin(), pom1.end() );
	result.insert( result.end(), pom2.begin(), pom2.end() );
	
	return result;
}

vector<point> collect(int idxX, int t)
{
	vector<point> result;
	
	for (auto i : Widx)
	{
		result.insert(result.end(), tree[t][idxX][i].begin(), tree[t][idxX][i].end());
	}
	
	return result;
}

vector<point> findX(int w, int p, int k, int x, int y, int t)
{
	vector<point> result;
	
	if(k <= x || y <= p)
		return result;
	
	if(p < x && y < k)
	{
		result = collect(w, t);
		return result;
	}
	
	vector<point> pom1 = findX(w*2, p, (p+k)/2, x, y, t);
	vector<point> pom2 = findX(w*2+1, (p+k)/2+1, k, x, y, t);
	
	result.reserve( pom1.size() + pom2.size() );
	result.insert( result.end(), pom1.begin(), pom1.end() );
	result.insert( result.end(), pom2.begin(), pom2.end() );
	
	return result;
} 

int main()
{
	//wczytywanie
	scanf("%d %d", &n, &m);
	
	wall[0].resize(n);
	wall[1].resize(m);
	
	int x1, x2, y1, y2;
	
	point p;
	
	p.w = 0;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		x1 += 1000; x2 += 1000; y1 += 1000; y2 += 1000;
		
		wall[0][i] = makeWin(x1, y1, x2, y2);
		
		p.idx = i;
		
		tree[0][x1][y1].push_back(p);
		tree[0][x1][y2].push_back(p);
		tree[0][x2][y1].push_back(p);
		tree[0][x2][y2].push_back(p);
	}
	
	p.w = 1;
		
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
		x1 += 1000; x2 += 1000; y1 += 1000; y2 += 1000;
	
		wall[1][i] = makeWin(x1, y1, x2, y2);
		
		p.idx = i;
		
		tree[1][x1][y1].push_back(p);
		tree[1][x1][y2].push_back(p);
		tree[1][x2][y1].push_back(p);
		tree[1][x2][y2].push_back(p);
	}
	
	//przepychanie wartości na drzewie
	
	//program
	t = 1;
	
	queue<win> light, lightNew, lightRef;
	vector<point> findings;
	bitset<603> used;
	
	for (int i = 0; i < m; ++i) //rozważam oddzielnie każde okno przeciwległego budynku
	{
		light.push(wall[1][i]);
		
		while(!light.empty())
		{
			while(!light.empty()) //szukanie odbić
			{
				Widx = findY(1, 0, R-1, light.front().y1, light.front().y2);
				findings = findX(1, 0, R-1, light.front().x1, light.front().x2, t);
				
				used.reset();
				
				for(point j : findings)
				{
					if(used[j.idx])
						continue;
					
					used[j.idx] = 1;
					
					x1 = max(wall[j.w][j.idx].x1, light.front().x1);
					y1 = max(wall[j.w][j.idx].y1, light.front().y1);
					x2 = min(wall[j.w][j.idx].x2, light.front().x2);
					y2 = min(wall[j.w][j.idx].y2, light.front().y2);
					
					lightNew.push(makeWin(x1, y1, x2, y2));
					
					if(!t)
						visit[j.idx] = 1;
				}
			}
			
			while(!lightNew.empty()) //przekształcenie
			{
				lightRef.push(lightNew.frpont().reflect());
				lightNew.pop();
			}
			
			swap(light, lightRef);
			t ^= 1; //zmieniam ścianę
		}
	}
	
	
	return 0;
}
