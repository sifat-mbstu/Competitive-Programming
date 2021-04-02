#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1000000007;
ll ten[2100], dp[2002][2002][2][2];
int m, d, sz;
string A,B;

ll fun(int pos, int rem, int choto, int boro)
{
    if(pos==sz)
    {
        if(rem==0)
        {
            return 1LL;
        }
        return 0LL;
    }
    ll &ret = dp[pos][rem][choto][boro];
    if(ret != -1) return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos] - '0';
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        ll now = rem*10;
        now += i;
        now %= m;
        int nrem = now;
        if(pos%2!=0)
        {
            if(i==d) ret = (ret + fun(pos+1, nrem, choto|(i<hi), boro|(i>lo)))%mod;
        }
        else
        {
            if(i!=d) ret = (ret + fun(pos+1, nrem, choto|(i<hi), boro|(i>lo)))%mod;
        }
    }
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&m,&d);
    cin >> A >> B;
    sz = A.size();
    ll res = fun(0,0,0,0);
    printf("%lld\n",res);
}
