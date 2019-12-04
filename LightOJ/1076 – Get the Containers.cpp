#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[1010];
ll n, m;
ll MAX = 0;
int check(ll val)
{
    MAX = 0;
    ll cnt = 0, sum = 0;
    for(int i=0; i<n;)
    {
        if(ara[i] > val){return 2;}
        if(sum+ara[i]<=val)
        {
            sum += ara[i];
            MAX = max(MAX, sum);
            i++;
        }
        else
        {
//            printf("sum = %lld\n",sum);
//            getchar();
            cnt++;
            sum = 0;
        }
    }
    if(sum > 0) {cnt++; }
//    getchar();
    MAX = max(MAX, sum);
    if(cnt > m)
    {
        return 2;
    }
    return 1;

}


int main()
{
    ll ind = 0;
    ll TC;
    cin >> TC;
    while(TC--){
    scanf("%lld %lld",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&ara[i]);
    }
    ll lo = 0, hi = 1010000001;
    ll ans=1010000001;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
//        printf("mid = %lld",mid);
        ll ch = check(mid);
//        getchar();
        if(ch==2)
        {
            lo = mid+1;
//            printf("1 mid = %lld\n",mid);
        }
        else
        {
            ans = min(MAX, ans);
//            cout << MAX << endl;
            hi = mid-1;
        }
    }
    printf("Case %lld: %lld\n",++ind, ans);
//    cout << ans << endl;
    }
}
