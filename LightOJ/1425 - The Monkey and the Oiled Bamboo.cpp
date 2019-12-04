///Accepted (0.304 Second)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll TC, ind = 0;
    cin >> TC;
    while(TC--){
    ll n, ara[100005];
    int v[100005];
    cin >> n;
    scanf("%lld",&ara[0]);
    ll MAX = ara[0];
    v[0] = ara[0];
    int x = 1;
    for(int i=1; i<n; i++)
    {
            scanf("%lld",&ara[i]);
            ll dif = ara[i] - ara[i-1];
            MAX = max(MAX, dif);
            v[x++] = dif;
    }
    ll cur_max = MAX;
    bool prob = 0;
    for(int i=0; i<x; i++)
    {
        if(cur_max==v[i])
        {
            cur_max--;
        }
        else if(cur_max<v[i])
        {
            prob = 1;
            break;
        }
    }
    if(prob){MAX++;}
    printf("Case %lld: %lld\n",++ind, MAX);
    }
}
