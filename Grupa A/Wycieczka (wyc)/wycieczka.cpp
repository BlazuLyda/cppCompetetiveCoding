#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;

//rest
bitset<40004> cnt;
vector<pair<int,int>> scaling;
vector<pair<int, pair<int,int>>> query[202];

//graph
vector<int> conns[40004];
int attr[40004];

//LCA
int LCAidx[40004];
vector<pair<int,int>> LCAtrav[80008]; //<node index, node depth>
int Litr = 1;
int maxPot[80008];

void findMaxPot()
{
	maxPot[0] = -1;
	
	for (int i = 1; i <= 2*n; i *= 2)
	{
		maxPot[i] = maxPot[i/2] + 1;
	}
	
	for (int i = 3; i <= 2*n; ++i)
	{
		maxPot[i] = max(maxPot[i-1], maxPot[i]);
	}
}

pair<int,int> minDepth(pair<int,int> w1, pair<int,int> w2)
{
	if(w1.ss < w2.ss)
		return w1;
	
	return w2;
}

void findMin()
{
	int max2;
	
	for (int i = 1; i < 2*n; ++i)
	{
		max2 = 1;
		
		for (int j = 2; j <= i; j *= 2) //j=1 to po prostu głębokość wierzchołka na danej pozycji
		{	
			LCAtrav[i].push_back(minDepth(LCAtrav[i][max2 - 1], LCAtrav[i - j/2][max2 - 1]));
			
			++ max2;
		}
	}
}

int LCA(int w1, int w2)
{
	int w1idx = LCAidx[w1], w2idx = LCAidx[w2];
	
	if(w1idx > w2idx)
		swap(w1idx, w2idx);
	
	int pot = maxPot[w2idx - w1idx + 1];
	
	return minDepth(LCAtrav[w2idx][pot], LCAtrav[w1idx + (1<<pot) - 1][pot]).ff;
}

//Path
pair<int,int> Pathidx[40004];
int Pathtrav[80008];
int Pitr = 1;

void DFS(int w, int o, int d)
{
	LCAtrav[Litr].push_back({attr[w], d});
	LCAidx[w] = Litr;
	++Litr;
	
	Pathtrav[Pitr] = attr[w];
	Pathidx[w].ff = Pitr;
	++Pitr;
	
	for (auto i : conns[w])
	{
		if(i != o)
		{
			DFS(i, w, d+1);
			
			LCAtrav[Litr].push_back({attr[w], d});
			++Litr;
		}
	}
	
	Pathtrav[Pitr] = attr[w];
	Pathidx[w].ss = Pitr;
	++Pitr;
}

void add(int a)
{
	
}


int main()
{	
	scanf("%d %d", &n, &m);
	
	int a, b;
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		
		scaling.push_back({a, i});
	}
	
	//skalowanie
	sort(scaling.begin(), scaling.end());
	
	int last = 0, tmp = 0;
	
	for (auto i : scaling)
	{
		if(i.ff != last)
			++tmp;
		
		attr[i.ss] = tmp;
		last = i.ff;
	}
	
	//wczytywanie połączeń
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	DFS(1, 0, 1);
	
	findMaxPot();
	
	findMin();
	
	//for (int i = 1; i <= 2*n; ++i)
	//{
		//printf("i:%d\n", i);
		
		//for (auto j : LCAtrav[i])
		//{
			//printf("\tnode:%d depth:%d\n", j.ff, j.ss);
		//}
	//}
	
	//wczytywanie zapytań
	int sq = sqrt(n), p, k;
	
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		
		p = max(Pathidx[a].ff, Pathidx[b].ff);
		k = min(Pathidx[a].ss, Pathidx[b].ss);
		
		if(p > k)
			swap(p, k);
		
		query[p / sq].push_back({i, {p, k}});
	}
	
	
	
	return 0;
}