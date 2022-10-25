#include <bits/stdc++.h>

using namespace std;

int T;
string s;
int res, n, m;
bool b;

int main() {
	cin >> T;
	
	while (T--) {
		cin >> s;
		res = 0;
		n = (int)s.length();
		
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				
				m = (j - i + 1);
				
				if (m % 4 == 0) {
					m /= 4;
					b = true;
					
					for (int k = 0; k < m; k++) {
						if (s[i+k] != s[i+k+2*m]) {
							b = false;
							break;
						}
						
						if (s[i+k+m] != s[i+k+3*m]) {
							b = false;
							break;
						}
						
						if (s[i+k] != s[i-k-1+2*m]) {
							b = false;
							break;
						}
					}
					
					if (b) res = max(res, 4*m);
				}				
			}
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
