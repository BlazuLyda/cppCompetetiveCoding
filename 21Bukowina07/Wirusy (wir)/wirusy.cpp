#include <bits/stdc++.h>

using namespace std;

struct node {
	node* idx[2];
	node* addit;
	bool bad;
};

int n;

node trie[30030];
int idxt = 1;
char[] in;
vector<string> ins;

bool cmp(string a, string b) {
	return a.length() < b.length();
}

int main()
{
	trie[1] = {{0, 0}, 0};
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", in);
		ins.push_back(in);
	}
	sort(ins.begin(), ins.end(), cmp);
	
	int sidx, num; 
	node* last, add, cur;
	
	for (auto s : ins) {
		while (true) {
			c = 0;
			last = *trie[1];
			add = *trie[1];
			
			if (s[sidx] == '0') num = 0;
			else if (s[sidx] == '1') num = 1;
			else break;
			
			if (last -> idx[num] == 0) {
				last -> idx[num] = *trie[++idxt];
				cur = *trie[idxt];
				*cur = {{0, 0}, 0, 0};
				
				if (sidx == 0) cur->addit = trie[1];
				else {
					add = last -> addit;
					
					while (add -> idx[num] == 0) {
						add = add -> addit;
					}
					cur -> addit = add -> idx[num];
				}
			}
			
			last = trie[last].idx[cur];
			sidx++;
		}
		
		trie[last].bad = 1;
	}
	
	return 0;
}
