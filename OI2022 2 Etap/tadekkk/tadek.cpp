#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m;
string person, skill;
int skillsnumber, level;
map<string, string> skills;
set<string>MM;
int num;
vector<pair<int, string>>wynik;
vector<string> pom;
map<string, vector<string>> ansans;

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
            ansans[doopa].push_back(req);
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
            wynik.pb(make_pair(b, doopa));
            num++;
        }
        //cout << endl;
    }
    
    sort(wynik.begin(), wynik.end());

    cout<<num<<"\n";
    int i=0;
    for(i; i<wynik.size(); i++)
    {
        cout << wynik[i].second << endl;
        for(auto j : ansans[wynik[i].second]){
            cout << skills[j] << " ";
        }
        cout << endl;
    }


}