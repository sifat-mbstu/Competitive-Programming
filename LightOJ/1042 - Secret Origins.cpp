#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check(ll val)
{
    ll cnt = 0;
    for(ll i=0; i<=32; i++)
    {
        if ((val >> i)&1) cnt++;
    }
//    printf("val = %lld __ cnt = %lld\n",val,cnt);
    return cnt;
}
int main()
{
    ll TC, val,x=0;
    cin >> TC;
    while(TC--)
    {
        cin >> val;
        ll cnt = check(val);
 //       printf("---> val = %lld -- cnt = %lld\n",val,cnt);
        ll i;
        for(i=val+1; ; i++)
        {
            if(check(i)==cnt)
                break;
        }
        printf("Case %lld: %lld\n",++x,i);
    }
}
