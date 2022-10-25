#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <vector>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

vector <pair <int,pair <int,int> > > v;
int rep[1000];
int find(int w)
{
    if(rep[w]!=w) rep[w]=find(rep[w]);
    return rep[w];
}

unsigned long long D[64] = {1, 3, 8, 20, 48, 112, 256, 576, 1280, 2816, 6144, 13312, 28672, 61440, 131072, 278528, 589824, 1245184, 2621440, 5505024, 11534336, 24117248, 50331648, 104857600, 218103808, 452984832, 939524096, 1946157056, 4026531840, 8321499136, 17179869184, 35433480192, 73014444032, 150323855360, 309237645312, 635655159808, 1305670057984, 2680059592704, 5497558138880, 11269994184704, 23089744183296, 47278999994368, 96757023244288, 197912092999680, 404620279021568, 826832744087552, 1688849860263936, 3448068464705536, 7036874417766400, 14355223812243456, 29273397577908224, 59672695062659072, 121597189939003392, 247697979505377280, 504403158265495552, 1026820715040473088};
unsigned long long pref[64] = {1, 4, 12, 32, 80, 192, 448, 1024, 2304, 5120, 11264, 24576, 53248, 114688, 245760, 524288, 1114112, 2359296, 4980736, 10485760, 22020096, 46137344, 96468992, 201326592, 419430400, 872415232, 1811939328, 3758096384, 7784628224, 16106127360, 33285996544, 68719476736, 141733920768, 292057776128, 601295421440, 1236950581248, 2542620639232, 5222680231936, 10720238370816, 21990232555520, 45079976738816, 92358976733184, 189115999977472, 387028092977152, 791648371998720, 1618481116086272, 3307330976350208, 6755399441055744, 13792273858822144, 28147497671065600, 57420895248973824, 117093590311632896, 238690780250636288, 486388759756013568, 990791918021509120, 2017612633061982208};

bitset<64> Abin, Bbin;

long long unsigned func(long long unsigned A, long long unsigned B)
{
	long long unsigned res = 0, sub = 0, a = 0, b = 0;
		
		for (unsigned long long p = 0; p <= 54; p++)
		{
			Abin[p] = A & (1LLU << p);
			Bbin[p] = B & (1LLU << p);
			
			if (Abin[p])
				a = p;
			
			if (Bbin[p])
				b = p;
		}
		
		if (A == B)
		{
			return 0;
		}
		
		//krańce przedziałów
		unsigned long long At = A, Bt = B, num;
		
		for (unsigned long long p = b - 1LLU; p < b; p--)
		{
			num = ( 1LLU << p );
			
			if(Bbin[p] && !Abin[p])
				Bt = Bt ^ num;
			
			else if (!Bbin[p] && Abin[p])
			{
				if ( (Bt ^ num) <= B )
					Bt = Bt ^ num;
					
				else if ( (At ^ num) >= A )
					At = At ^ num;
					
				else
					res += num;
			}			
		}
				
		if (A != 0)
			sub += pref[a];
		
		res += pref[b];
		
		for (unsigned long long p = 0; p <= 54; p++)
		{
			if(!Abin[p] && p < a)
				res += D[p];
				
			if(!Bbin[p] && p < b)
				sub += D[p];
		}
			
		res -= sub;
		
		return res;
}

int main()
{

    srand(time(0));
	
	int q;
	long long a, b;
	
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        a=rand()%100+8754567;
        b=rand()%100;
        b+=a;
        if(a>b) swap(a,b);

        while(__builtin_clzll(a)==__builtin_clzll(b)&&a)
        {
            long long h=1LL<<(63-__builtin_clzll(a));
            a-=h;
            b-=h;
        }
        v.clear();
        for(int i=a;i<=b;i++)
        {
            rep[i]=i;
            for(int j=i+1;j<=b;j++)
            {
                v.push_back({i^j,{i,j}});
            }
        }
        sort(v.begin(),v.end());

        long long res=0;
        for(auto i: v)
        {
            
            if(find(i.ss.ff)!=find(i.ss.ss))
            {
                res+=i.ff;
                rep[find(i.ss.ff)]=find(i.ss.ss);
            }
        }

        if(func(a,b)!=(unsigned long long)res)
        {
            cout<<"wrong "<<a<<" "<<b<<endl;
        }
        else printf("correct %d\n", i);
    }

    return 0;
}