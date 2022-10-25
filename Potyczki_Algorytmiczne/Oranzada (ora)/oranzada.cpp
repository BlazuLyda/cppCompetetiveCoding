#include <bits/stdc++.h>

using namespace std;

int n, k;
bitset<500500> used;

int main() {
    scanf("%d %d", &n, &k);
    
    int fill = 0;
    int a;
    long long wyn = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        
        if (used[a]) continue;
        used[a] = 1;
        
        wyn += (long long) i - fill;
        fill++;
        
        if (fill == k) break;
    }
    
    if (fill < k) printf("-1\n");
    else printf("%lld\n", wyn);
    
    return 0;
}