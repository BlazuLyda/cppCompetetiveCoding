#include <bits/stdc++.h>
#include "konlib.h"

using namespace std;

int main()
{
	int n = nalesniki();
	if (lepszy(2,6,1,n)) {
		odpowiedz(2,6);
	} else {
		odpowiedz(1,n);
	}
	return 0;
}
