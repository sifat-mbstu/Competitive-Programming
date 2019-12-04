#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll two=0;
ll five=0;
ll n,r,p,q;
ll Find(ll  n, ll d)
{
    ll cnt = 0;
    for (ll i=d; n/i>=1; i *= d)
    {
        cnt += n/i;
    }
    return cnt;
}
ll check(ll n, ll d)
{
    ll cnt = 0;
    while(n%d==0)
    {
        n /= d;
        cnt++;
    }
    return cnt;
}
/*void check_facr(ll n)
{
    for(ll i=r+1; i<=n ;i++)
    {
        ll Num = i;
        while(Num%2==0) {Num /= 2;two++;}
        while(Num%5==0) {Num /= 5;five++;}
    }
}*/
void check_fact(ll n)
{
    for(ll i=2; i<=n ;i++)
    {
        ll Num = i;
        while(Num%2==0) {Num /= 2;two++;}
        while(Num%5==0) {Num /= 5;five++;}
    }
}
int main()
{
    ll TC,ind = 0;
    cin >> TC;
    while(TC--){

    ll f_2 = 0;
    ll f_5 = 0;
    cin >> n >> r >> p >> q;

    ll m2 = check(p,2)*q;
    ll m5 = check(p,5)*q;

    f_2 = m2 + Find(n,2) - Find(r,2) - Find(n-r,2);
    f_5 = m5 + Find(n,5) - Find(r,5) - Find(n-r,5);

    ll Min = min(f_2, f_5);
    printf("Case %lld: %lld\n",++ind, Min);
    }
}
