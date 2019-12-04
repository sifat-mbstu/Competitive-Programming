#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll n,i,gcd,rem,a,b,gcd1,TC;
    cin >> TC;
    while(TC--){
    scanf("%llu",&n);
    gcd = n/2;
    gcd1 = 1;
    gcd = max(gcd,gcd1);
    printf("%llu\n",gcd);
    }
}
