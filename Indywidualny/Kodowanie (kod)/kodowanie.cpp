#include <bits/stdc++.h>

using namespace std;

struct Node {
	int conns[2]; // połączenia dla krawędzi 0 i 1
	int len; // głębokość
	bool vis; // czy odwiedzone
	bool let; // czy kończą się tu jakieś literki
	vector<int> jumpTo; // literki pod nami w drzewie
	vector<int> back; // krawędzie wsteczne
}

int n, t = 2;
vector<Node> trie(2);
priority_queue <pair<int, int>> que; // <długość słowa (do sortowania po najkrótszym), pozycja po skoku>

vector<int> dfs(int w, int o, int num) {
	// tworzenie krawędzi wstecznych
	trie[w].len = trie[o].len + 1;
	trie[w].back.resize(trie[w].len);
	
	if (trie[0].conns[num]) trie[w].back[1] = trie[0].conns[num];
	
	for (int k = 1; k < trie[o].len; k++) {
		trie[w].back[k+1] = trie[k].conns[num];
	}
	
	// wywoływanie się w synach i zbieranie literek do których możemy dojść
	vector<int> ret;
	
	if (trie[w].conns[0]) {
		auto it = trie[w].jumpTo.begin();
		ret = dfs(trie[w].conns[0], w, 0);
		trie[w].jumpTo.insert(it, ret.begin(), ret.end());
	}
	if (trie[w].conns[1]) {
		auto it = trie[w].jumpTo.begin();
		ret = dfs(trie[w].conns[1], w, 1);
		trie[w].jumpTo.insert(it, ret.begin(), ret.end());
	}
	
	return trie[w].jumpTo;
}

int main() {
	scanf("%d", &n);
	
	char c, num;
	char s[1001];
	int pre;
	
	// tworzenie drzewa trie
	for (int i = 1; i <= n; i++) {
		scanf("%c %s", &c, s);
		
		pre = 0;
		
		for (int j = 0; s[j]; j++) {
			num = s[j] - '0';
			
			if (!trie[pre].conns[num]) {
				trie[pre].conns[num] = t;
				trie.push_back(Node());
				t++;
			}
			
			pre = trie[pre].conns[num];
		}
		
		// tutaj kończy się jakaś literka
		trie[pre].let = 1;
		trie[pre].jumpTo.push_back(i);
	}
	

	
	return 0;
}
