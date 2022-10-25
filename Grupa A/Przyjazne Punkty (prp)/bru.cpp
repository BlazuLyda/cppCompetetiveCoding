#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ff first
#define ss second

using namespace std;

int n;
long long result;
pair <int,int> a[100001],b[100001];
int c[100001];

vector <int> tpr[100001],tsu[100001];

bool comp(int a1,int a2)
{
    return c[a1]<c[a2];
}

void upr(int w,int idx)
{
    while(w<=n)
    {
        while(tpr[w].size()&&tpr[w].back()<idx) tpr[w].pop_back();
        tpr[w].push_back(idx);
        w+=w&-w;
    }
}

void usf(int w,int idx)
{
    w=n-w+1;
    while(w<=n)
    {
        while(tsu[w].size()&&tsu[w].back()>idx) tsu[w].pop_back();
        tsu[w].push_back(idx);
        w+=w&-w;
    }
}

long long qpr(int w)
{
    int mx=0,ret=0;
    while(w)
    {
        auto h=upper_bound(tpr[w].begin(),tpr[w].end(),mx,comp);
        if(h!=tpr[w].end())
        {
            mx=tpr[w].back();
            ret+=tpr[w].end()-h;
        }
        w&=w-1;
    }
    return ret;
}

long long qsu(int w)
{
    w=n-w+1;
    int mx=0,ret=0;
    while(w)
    {
        auto h=upper_bound(tsu[w].begin(),tsu[w].end(),mx,comp);
        if(h!=tsu[w].end())
        {
            mx=tsu[w].back();
            ret+=tsu[w].end()-h;
        }
        w&=w-1;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].ff,&a[i].ss);
        b[i]=make_pair(a[i].ss,i);
    }

    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        a[b[i].ss].ss=i;
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        c[a[i].ss]=i;
    }

    for(int i=1;i<=n;i++)
    {
        result+=qpr(a[i].ss)+qsu(a[i].ss);
        upr(a[i].ss,a[i].ss);
        usf(a[i].ss,a[i].ss);
    }

    printf("%lld\n",result);

    return 0;
}