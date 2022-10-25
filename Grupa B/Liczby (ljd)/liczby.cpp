#include <bits/stdc++.h>

using namespace std;

vector<int> dec;
vector<int> bin;
int count[1000];

vector<int> decToBin(int a)
{
	vector<int> res;
	
	while(a)
	{
		res.push_back(a&1);
		a>>=1;
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	
	cin >> s;
	
	for (auto i : s)
		dec.push_back(i - '0')
	
	int r;
	
	reverse(dec.begin(), dec.end());
	
	while(dec.size()) //change to binary system
	{	
		for (int i = (int)dec.size()-1; i >= 0; --i)
		{
			dec[i] += 10*r;
			r = (dec[i]&1);
			dec[i] >>= 1;
		}
		
		bin.push_back(r);
		
		if(dec[dec.size()-1] == 0)
			dec.pop_back();
	}
	
	//counting the dots
	vector<int> result = {0};
	
	long long pot;
	vector<int> add = decToBin((int)bin.size());
	
	for (int i = (int)bin.size()-1; i >= 0; --i)
	{
		
	}
	
	return 0;
}