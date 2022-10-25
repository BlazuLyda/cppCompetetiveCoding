#include <bits/stdc++.h>

using namespace std;

int T;
string s;
int res, n, c, cp, im, im2, mini; //wynik, długość słowa, obecny środek, prawa strona środka, i odbite, minimalne LPS i oraz im
int LPS[600600]; //najdłuższy parzysty podciąg palindromiczny w indeksie

int manacher() {
	res = 0;
	n = (int)s.length();
		
	n *= 2;
	c = 0;
	cp = 0;
	
	for (int i = 2; i <= n; i += 2)
	{
		im = max(2*c - i, 0); //palindrom symetryczny względem środka do obecnego palindromu
		im2 = max(2*im - i, 0);
		LPS[i] = min(LPS[im], max(cp - i, 0));
		
		mini = min(LPS[i], LPS[im]);
		if (( (i - im) % 4 == 0 ) && ( i - mini <= im + mini )) { //sprawdzam czy palindromy tworzą specjalne podsłowo
			res = max(res, i - im);
		}
		
		mini = min(LPS[i], LPS[im2]);
		if (( (i - im) % 2 == 0 ) && ( i - mini <= im2 + mini )) { //sprawdzam czy palindromy tworzą specjalne podsłowo
			res = max(res, i - im2);
		}
		
		
		while (0 < i - LPS[i] && i + LPS[i] < n) { //wydłużam obecny palindrom
			if (s[ (i + LPS[i]) / 2 ] == s[ (i - LPS[i]) / 2 - 1 ]) {
				LPS[i] += 2;
				
				//if (( LPS[i] % 4 == 0 ) && ( LPS[max(0, i-2*LPS[i])] >= LPS[i] )) { //sprawdzam x2 ^ 
					//res = max(res, 2*LPS[i]);
				//}
			}
			else break;
		}
		
		//printf("(%c_%c) idx:%d im:%d LPS:%d c:%d cp:%d | RES:%d\n", s[i/2-1], s[i/2], i, im, LPS[i], c, cp, res);
		
		if (i + LPS[i] > cp) { //sprawdzam czy obecny palindrom nie jest dłuższy niż obecny środek
			c = i; 
			cp = i + LPS[i];
		}
	}
	
	return res;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	
	while(T--) {
		cin >> s;
		cout << manacher() << "\n";
	}
	
	return 0;
}
