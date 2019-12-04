#include<bits/stdc++.h>
using namespace std;
int main() {
    long long L, R;
    while (scanf("%lld %lld", &L, &R) == 2 && L) {
        long long ret = R / 5 - L/5 + 1;
        printf("%lld\n", ret);
    }
    return 0;
}
