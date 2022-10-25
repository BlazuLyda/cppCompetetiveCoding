#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const int inf = 1000000000; 

int n, m, k;
int res;

// in     - 0
// b      - 1   : 200
// a(in)  - 201 : 400
// a(out) - 401 : 600
// c      - 601 : 800
// out    - 801

struct vertice
{
	int node, prof, flow;
};

vertice mkVert(int node, int prof, int flow)
{
	vertice res = {.node = node, .prof = prof, .flow = flow};
	return res;
}

//Graph
vector<int> graph[1000];
vector<vertice> vert; //wierzcholek, wartość, przeplyw
int value[1000], siz[1000];
int idx;

//SPFA
queue<int> que; //wierzcholek
bitset<1000> onQue;
int from[1000];

void SPFA()
{
    int w, v;
    
    fill(value, value+1000, -inf);
    value[0] = 0;
    onQue[0] = 1;
    que.push(0);
    
    while (!que.empty())
    {
        w = que.front();
        que.pop();
        onQue[w] = 0;
        
        for (int i : graph[w]) //zmienić i na vert[i] lub inaczej
        {
			v = vert[i].node;
			
            if ((value[w] + vert[i].prof > value[v]) && vert[i].flow)
            {
                value[v] = value[w] + vert[i].prof;
                from[v] = w;
                
                if(!onQue[v])
                {
                    que.push(v);
                    onQue[v] = 1;
                }
            }
        }
    }
    
    //update wyniku
    res += value[801];
    
    //backtrack najlepszej ścieżki
    w = 801; //ujscie
    
    
    //printf("\n<<<BACKTRACK>>>\n");
    
    while (w) //dopóki nie dotarliśmy do źródła, ktore ma numer 0
    {
		//printf("w:%d val:%d\n", w, value[w]);
		
        for (auto i : graph[w])
        {
			v = vert[i].node;
			
            if (v == from[w])
            {
                vert[i].flow = 1;  //krawędź wsteczna
                vert[i^1].flow = 0;
				w = v;
				break;
            }
        }
    }
}

int func(int u, int v)
{
    return (( u+v ) * ( u^v )) % m;
}

void printConns(int w)
{
	printf("\tw: %d\n", w);
	for (auto i : graph[w])
		printf("v:%d prof:%d flow:%d\n", vert[i].node, vert[i].prof, vert[i].flow);
	printf("\n");
}

void printGraph(int z)
{
	printf("\n\n-----------------%d------------------\n", z);
	printf("\n<<<IN>>>:\n");
	printConns(0);
	
	printf("\n<<<B>>>:\n");
	for (int i = 1; i <= n; ++i)
		printConns(i);
		
	printf("\n<<<A(in)>>>:\n");
	for (int i = 1; i <= n; ++i)
		printConns(i + 200);
		
	printf("\n<<<A(out)>>>:\n");
	for (int i = 1; i <= n; ++i)
		printConns(i + 400);
		
	printf("\n<<<C>>>:\n");
	for (int i = 1; i <= n; ++i)
		printConns(i + 600);
	
	printf("\n<<<OUT>>>:\n");
	printConns(801);
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    
    int f;
    
    for (int i = 1; i <= n; i++) //a
    {
        scanf("%d", &siz[ i+200 ]);
        siz[ i+400 ] = siz[ i+200 ];
	}
    
    for (int i = 1; i <= n; i++) //b
        scanf("%d", &siz[ i ]);
    
    for (int i = 1; i <= n; i++) //c
        scanf("%d", &siz[ i+600 ]);
    
    vert.reserve(200000);
    
    for (int i = 1; i <= n; i++) // in --> b
    {
        graph[0].push_back(idx);
        vert.push_back( mkVert(i, 0, 1) );
        
        graph[i].push_back(idx+1);
        vert.push_back( mkVert(0, 0, 0) );
        
        idx+=2;
    }
    
    for (int i = 1; i <= n; i++) // b --> a
    {
        for (int j = 1; j <= n; j++)
        {
            f = func(siz[i], siz[j+200]);
            
            graph[i].push_back(idx);
            vert.push_back( mkVert(j+200, f, 1) );
            
            graph[j+200].push_back(idx+1);
            vert.push_back( mkVert(i, -f, 0) );
            
            idx+=2;
        }
    }
    
    for (int i = 1; i <= n; i++) // a(in) --> a(out)
    {
        graph[i+200].push_back(idx);
        vert.push_back( mkVert(i+400, 0, 1) );
            
        graph[i+400].push_back(idx+1);
        vert.push_back( mkVert(i+200, 0, 0) );
            
        idx+=2;
    }
    
    
    for (int i = 1; i <= n; i++) // a --> c
    {
        for (int j = 1; j <= n; j++)
        {
            f = func(siz[i+400], siz[j+600]);
            
            graph[i+400].push_back(idx);
            vert.push_back( mkVert(j+600, f, 1) );
            
            graph[j+600].push_back(idx+1);
            vert.push_back( mkVert(i+400, -f, 0) );
            
            idx+=2;
        }
    }
    
    for (int i = 1; i <= n; i++) // c --> out
    {
        graph[i+600].push_back(idx);
        vert.push_back( mkVert(801, 0, 1) );
        
        graph[801].push_back(idx+1);
        vert.push_back( mkVert(i+600, 0, 0) );
        
        idx+=2;
    }
    
    
    
    //SPFA 
	for (int i = 0; i < k; ++i)
	{
		//printGraph(i);
		SPFA();
	}
	
	printf("%d\n", res);
    
    return 0;
}