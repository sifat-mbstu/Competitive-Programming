#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll TC, idx = 0LL;
    cin >> TC;
    while(TC--)
    {
        ll n,s1,v1,s2,v2,Max=0;
        cin >> n >> s1 >> v1 >> s2 >> v2;
        if(s1*s1>n)
        {
            for(ll i=0; ; i++)
            {
                ll multi = s1*i;
                if(multi>n)break;
                ll rest = n-multi;
                rest = rest/s2;
                ll ret = i*v1 + rest*v2;
                Max = max(Max,ret);
            }
        }
        else if(s2*s2>n)
        {
            for(ll i=0; ; i++)
            {
                ll multi = s2*i;
                if(multi>n)break;
                ll rest = n-multi;
                rest = rest/s1;
                ll ret = i*v2 + rest*v1;
                Max = max(Max,ret);
            }
        }
        else
        {
            double pro1 = (double)v1/(double)s1;
            double pro2 = (double)v2/(double)s2;
            if(pro1<pro2)
            {
                swap(v1,v2);
                swap(s1,s2);
            }
            for(ll i=0; i<=s1; i++)
            {
                ll multi = i*s2;
                if(multi>n) break;
                ll rest = n-multi;
                rest = rest/s1;
                ll ret = i*v2 + rest*v1;
                Max = max(Max,ret);
            }

        }
        printf("Case #%lld: %lld\n",++idx,Max);
    }
}
