#include <iostream>
#include <stdio.h>

using namespace std;

int n,s,z;
bool x[100001],y[100001];
int a,b;

int main()
{
    cin>>s;
    srand(s);
    int n=5;
    int z=7;
    
    cout<<n<<endl;
    while(n)
    {
        a=rand()%z+1;
        b=rand()%z+1;
        if(!x[a]&&!y[b])
        {
            cout<<a<<" "<<b<<endl;
            x[a]=true;
            y[b]=true;
            n--;
        }
    }


    return 0;
}