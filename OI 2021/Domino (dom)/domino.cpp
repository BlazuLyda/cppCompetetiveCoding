#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

unsigned long long m;
unsigned long long fibRed[87] = {1, 1, 1, 1, 5, 1, 13, 7, 17, 55, 89, 1, 233, 377, 305, 329, 1597, 323, 4181, 2255, 5473, 17711, 28657, 161, 75025, 121393, 98209, 105937, 514229, 104005, 1346269, 726103, 1762289, 5702887, 9227465, 34561, 24157817, 39088169, 31622993, 34111385, 165580141, 33489287, 433494437, 233802911, 567451585, 1836311903, 2971215073, 8346401, 7778742049, 12586269025, 10182505537, 10983760033, 53316291173, 10783446409, 139583862445, 75283811239, 182717648081, 591286729879, 956722026041, 10750060805, 2504730781961, 4052739537881, 3278735159921, 3536736619241, 17167680177565, 3472236254411, 44945570212853, 24241153416047, 58834515230497, 190392490709135, 308061521170129, 576914365601, 806515533049393, 1304969544928657, 1055742538989025, 1138818207635569, 5527939700884757, 1118049290473933, 14472334024676221, 7805576116155895, 18944531186571953, 61305790721611591, 99194853094755497, 1114587804280327, 259695496911122585, 420196140727489673, 339945818819306129};
unsigned long long div2[87] = {0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 4, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 5, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 4, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 6, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 4, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 5, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 4, 0, 0, 1};
unsigned long long div3[87] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0};

int cnt2, cnt3;
int res;

int main() {
	scanf("%llu", &m);
	
	if (m == 1) {
		printf("1");
		return 0;
	}
	
	while (m % 2 == 0) {
		m /= 2LLU;
		cnt2++;
	}
	
	while (m % 3 == 0) {
		m /= 3LLU;
		cnt3++;
	}
	
	for (int i = 86; i > 0; i--) {
		if (fibRed[i] == 1) continue;
		
		while (m % fibRed[i] == 0) {
			m /= fibRed[i];
			res += i+1;
			cnt2 -= div2[i];
			cnt3 -= div3[i];
		}
	}
	
	if (cnt2 < 0 || cnt3 < 0 || m != 1) {
		printf("NIE");
		return 0;
	}
	
	// szukanie reszty
	int d;
	
	// 144
	d = min(cnt2 / 4, cnt3 / 2);
	res += d * 12;
	cnt2 -= d * 4;
	cnt3 -= d * 2;
	
	// 8
	d = cnt2 / 3;
	res += d * 6;
	cnt2 -= d * 3;
	
	// 2 i 3
	res += cnt2 * 3;
	res += cnt3 * 4;
	
	printf("%d", res-1);
	
	return 0;
}
