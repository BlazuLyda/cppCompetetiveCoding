#include <bits/stdc++.h>
#define inf 10000000000

using namespace std;

int n, m;
float res = 0;

struct mat {
	long long tab[101][101];
	
	void print() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (this->tab[i][j] < 0) {
					printf("- ");
				} else {
					printf("%lld ", this->tab[i][j]);
				}
			}
			printf("\n");
		}
	}
};

mat operator*(mat a, mat b) {
		long long pom;
		mat ret;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				pom = -inf;
				
				for (int k = 1; k <= n; k++) {
					pom = max(pom, a.tab[i][k] + b.tab[k][j]);
				}
				
				ret.tab[i][j] = pom;
			}
		}
		
		return ret;
	}

mat conns;

int main() {
	scanf("%d %d", &n, &m);
	
	int a, b;
	long long c;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				conns.tab[i][j] = -inf;
			} else {
				conns.tab[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		conns.tab[a][b] = c;
	}
	
	mat pos = conns;
	
	//pos.print();
	
	for (int i = 2; i <= n + 1; i++) {
		pos = pos * conns;
		
		//printf("\n\tPo %d turze:\n", i);
		//pos.print();
		for (int k = 1; k <= n; k++) {
			//printf("Cykl %d: %lld, srednia: %f\n", k, pos.tab[k][k] ,(float)pos.tab[k][k] / (float)i);
			res = max(res, (float)pos.tab[k][k] / (float)i );
		}
		//printf("\n");
	}
	
	printf("%.4f", res);
	
	return 0;
}
