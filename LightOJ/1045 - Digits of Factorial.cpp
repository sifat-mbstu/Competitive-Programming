#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,base,TC;
#define lim 1000010
double LOG[lim];
void logari()
{
    for(int i = 1; i < lim; i++)
    {
        LOG [i] = log10(i) + LOG[i-1];
    }
}
 
ll base_fact_digit(ll n, ll base)
{
    ll i;
    double x = 0;
    x += LOG[n] / log10(base);
    /*
        My assumption:
        Hmm.. as (LOG[1] / LOG [8]) +  (LOG[2] / LOG [8]) + (LOG[3] / LOG [8]) + (LOG[4] / LOG [8]) = (LOG[1] + (LOG[1] + LOG [2] + LOG [3] + LOG [4]) / LOG [8])
    */
    ll num_of_digit = floor(x) + 1;
    return num_of_digit;
}
int main()
{
    ll TC,i;
    logari();
    scanf("%lld", &TC);
    for(i = 1; i<= TC; i++){
    scanf("%lld %lld",&n,&base);
    printf("Case %lld: %lld\n",i, base_fact_digit(n, base));
    }
}