#include <bits/stdc++.h>

using namespace std;

const unsigned long long P = 31;
int t;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	
	string s;
	int len, im, wyn;
	unsigned long long hl, hr, mul;
	
	while (t--) {
		cin >> s;
		len = s.length();
		
		hl = 0; hr = 0; mul = 1;
		wyn = 0;
		
		for (int i = 0; i < (len/2); i++) {
			im = len - i - 1;
			hl = (unsigned long long) (hl + (mul * (s[i] - 'a')));
			hr = (unsigned long long) ((s[im] - 'a') + P * hr);
			mul = (mul * P);
			
			// cout << i << ": " << hl << ", " << hr << "\n";
			
			if (hl == hr) {
				wyn += 2;
				hl = 0; hr = 0; mul = 1;
			}
		}
		
		if (len % 2 || (!(len % 2) && hr != hl)) wyn++;
		
		cout << wyn << '\n';
	}
	
	
	return 0;
}
