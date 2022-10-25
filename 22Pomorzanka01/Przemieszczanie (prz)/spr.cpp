#include <bits/stdc++.h>

using namespace std;

double tab[1010];

double getSum(int a, int b) {
	double sum = 0;
	
	for (int i = a; i <= b; i++) sum += tab[i];
	
	return sum;
}

void fillSeg(int a, int b, double v) {
	for (int i = a; i <= b; i++) tab[i] = v;
}

int main() {
	int n, q;
	
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < 1000; i++) {
		scanf("%lf", &tab[i]);
	}
	
	char c;
	int a, b;
	
	for (int i = 0; i < q-1; i++) {
		scanf(" %c %d %d", &c, &a, &b);
		
		
		double sum = getSum(a-1, b-1);
		double avg = sum / (b - a + 1);
		
		if(c == 'Z') {
			fillSeg(a-1, b-1, avg);
			printf("\t--zmiana--\n");
		}
		
		printf("(%d;%d)\n", a, b);
		printf("sum%d: %lf\n", i, sum);
		printf("avg%d: %lf\n\n", i, avg);
	}
	
	printf("wyn for 310: %lf\n", tab[310-1]);
	
	return 0;
}
