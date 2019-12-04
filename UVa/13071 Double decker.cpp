#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll bus, a, b, TC, sum;
    scanf("%lld",&TC);
    while(TC--)
    {
        scanf("%lld %lld",&a, &b);
        ll c = a + b;
        sum = c * (c+1) / 2;
        sum += (c - b);
        printf("%lld\n",sum+1);
    }
}
