#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

unsigned long long fib[87] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049, 12586269025, 20365011074, 32951280099, 53316291173, 86267571272, 139583862445, 225851433717, 365435296162, 591286729879, 956722026041, 1548008755920, 2504730781961, 4052739537881, 6557470319842, 10610209857723, 17167680177565, 27777890035288, 44945570212853, 72723460248141, 117669030460994, 190392490709135, 308061521170129, 498454011879264, 806515533049393, 1304969544928657, 2111485077978050, 3416454622906707, 5527939700884757, 8944394323791464, 14472334024676221, 23416728348467685, 37889062373143906, 61305790721611591, 99194853094755497, 160500643816367088, 259695496911122585, 420196140727489673, 679891637638612258};
//~ map<unsigned long long, int> m;
//~ map<int, int> cnt;

unsigned long long num;
int div2[87], div3[87]; 
unsigned long long fibRed[87];

set<unsigned long long> fibs;

unsigned long long fpow(unsigned long long a, int p) {
	unsigned long long res = 1;
	
	while (p) {
		if (p&1) res *= a;
		a *= a;
		p >>= 1;
	}
	
	return res;
}

int main() {
	for (auto i : fib) {
		fibs.insert(i);
	}
	
	unsigned long long b;
	
	for (auto i : fib) {
		printf("\t%llu\n", i);
		for (int d2 = 0; d2 <= 59; d2++) {
			for (int d3 = 0; d3 <= 37; d3++) {
				b = i * fpow(2, d2) * fpow(3, d3);
				if (b <= i) continue;
				if (fibs.find(b) != fibs.end()) {
					printf("%lld * %lld = %lld\n", i, fpow(2, d2) * fpow(3, d3), *fibs.find(b));
				}
			}
		}
	}
	
	//~ m[1] = 1;
	
	//~ for (unsigned long long i : fib) {
		//~ printf("%lld\n", i);
		//~ for (auto j : m) {
			//~ if (j.ff * i > 1000000000000000000ULL) break;
			//~ m[j.ff * i] += j.ss;
		//~ }
	//~ }
	
	//~ printf("---------------\n");
	
	//~ for (auto j : m) {
		//~ cnt[j.ss]++;
	//~ }
	
	//~ for (auto j : cnt) {
		//~ printf("%d -> %d\n", j.ff, j.ss);
	//~ }
	
	//~ printf("---------------\n");
	//~ int d2 = 0, d3 = 0;
	//~ int m2 = 0, m3 = 0;
	//~ int num, licz;
	
	//~ for (auto i : fib) {
		//~ if (i % 2 == 0) d2++;
		//~ if (i % 3 == 0) d3++;
		
		//~ // 2
		//~ licz = 0;
		//~ num = i;
		//~ while (num % 2 == 0) {
			//~ num /= 2;
			//~ licz++;
			
			//~ if (num == 1) printf("Bang 2 : %llu\n", i);
		//~ }
		//~ m2 = max(m2, licz);
		
		//~ // 3
		//~ licz = 0;
		//~ num = i;
		//~ while (num % 3 == 0) {
			//~ num /= 3;
			//~ licz++;
			
			//~ if (num == 1) printf("Bang 3 : %llu\n", i);
		//~ }
		//~ m3 = max(m3, licz);
	//~ }
	
	//~ printf("Podzielne przez 2 : %d, maksymalna potega : %d\n", d2, m2);
	//~ printf("Podzielne przez 3 : %d, maksymalna potega : %d\n", d3, m3);
	
	//~ printf("---------------\n");
	
	//~ for (int i = 0; i < 87; i++) {
		//~ num = fib[i];
		//~ while (num % 2 == 0) {
			//~ num /= 2LLU;
			//~ div2[i]++;
		//~ }
		//~ while (num % 3 == 0) {
			//~ num /= 3LLU;
			//~ div3[i]++;
		//~ }
		//~ fibRed[i] = num;
	//~ }
	
	//~ for (auto i : fibRed) printf("%llu, ", i);
	//~ printf("\n");
	//~ for (auto i : div2) printf("%d, ", i);
	//~ printf("\n");
	//~ for (auto i : div3) printf("%d, ", i);
	//~ printf("\n");
	
	return 0;
}
