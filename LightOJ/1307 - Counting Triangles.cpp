///Accepted (0.632 Second)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[2010];
ll binary(ll val, ll lo, ll hi)
{
    ll ans = -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(arr[mid] < val)
        {
            lo = mid+1;
            ans = mid;
        }
        else
        {
            hi = mid-1;
        }
    }
    return ans;
}
int main()
{
    ll TC, ind = 0;
    scanf("%lld",&TC);
    while(TC--){
    ll n;
    scanf("%lld",&n);
    for(ll i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    sort(arr, arr+n);
    ll res = 0;

//    for(ll i=0; i<n; i++)
//    {
//        printf("i = %lld\n",arr[i]);
//    }
    for(ll i = 0; i<n-2; i++)
    {
        for(ll j=i+1; j<n-1; j++)
        {
            ll cnt = binary(arr[i]+arr[j], j+1, n-1);
            if(cnt!=-1) cnt = cnt - j;
            else cnt = 0;
            res += cnt;
        }
    }
    printf("Case %lld: %lld\n",++ind, res);
    }
}
