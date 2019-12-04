#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX/3
#define pi acos(-1.0)
#define pii pair<int,int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define ll long long

ll binary(ll val)
{
    ll lo = 0;
    ll hi = 149000000;
    ll ans=0;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
//        cout << mid << endl;
//        getchar();
        ll now = (mid*(mid-3))/2;
        if(now == val)
        {
            return mid;
        }
        else if(now < val)
        {
            ans = mid;
            lo = mid+1;
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
    ll n,ind=0;
    while(cin >> n)
    {
        if(!n)break;
        ll ans = binary(n);
        ll dia = ans*(ans-3);
        dia = dia/2;
        if(dia != n)
            ans++;
        printf("Case %lld: %lld\n",++ind,ans);
//        cout << ans << endl;
    }
}
