#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m;
string person, skill;
int skillsnumber, level;
map<string, string> skills;
set<string>MM;
int num;
vector<string>wynik, pom;

int main(){
    scanf("%d%d", &n, &m);
    // cout << m;
    for(int i = 0; i < n; i++){
        cin >> person >> skillsnumber >> skill >> level;
        skills[skill] = person;
    }
    
    for(int i = 0; i < m; i++){
        string doopa;
        int a, b, c, d;
        cin >> doopa >> a >> b >> c >> d;
        //cout << doopa << endl;
        pom.resize(0);
        MM.clear();
        for(int j = 0; j < d; j++){
            string req;
            int reqlev;
            cin >> req >> reqlev;
            if(MM.end()==MM.find(req))
            {
                pom.pb(skills[req]);
                MM.insert(req);
            }
            else
            {
                pom.resize(0);
            }

           // cout << skills[req] << " ";
        }
        if(d==pom.size())
        {
            wynik.pb(".");
            wynik.pb(doopa);
            num++;
            wynik.insert(wynik.end(), pom.begin(), pom.end());
        }
        //cout << endl;
    }

	

    cout<<num<<"\n";
    int i=0;
    for(i; i<wynik.size(); i++)
    {
        if(wynik[i]==".")
        {
            if(i!=0)cout<<"\n";
            i++;
            cout<<wynik[i]<<"\n";
        }
        else
        {
            cout<<wynik[i]<<" ";
        }
    }


}