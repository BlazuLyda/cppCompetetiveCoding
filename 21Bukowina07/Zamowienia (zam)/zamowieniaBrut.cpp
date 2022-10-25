#include <bits/stdc++.h>

using namespace std;

int z, p, q;
string a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> z;
	
	bool cor;
	int wyn;
	
	while(z--) {
		cin >> a >> b;
		
		wyn = 0;
		p = a.length();
		q = b.length();
		
		for (int i = 0; i + q <= p; ++i)
		{
			cor = true;
			
			for (int j = 0; j < q; j++) {
				if (a[i+j] != '?' && b[j] != '?' && a[j+i] != b[j]) {
					cor = false;
					break;
				}
			}
			
			wyn += cor;
		}
		
		cout << wyn << "\n";
	}
	
	return 0;
}
