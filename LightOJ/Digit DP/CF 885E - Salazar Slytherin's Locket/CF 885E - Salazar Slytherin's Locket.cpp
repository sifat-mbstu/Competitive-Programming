#include<bits/stdc++.h>
using namespace std;

#define ll long long
string A,B;
int b,l,r,sz;
ll dp[65][1025][2][2][2][11];

ll fun(int pos, int mask, int suru, int choto, int boro, int Base)
{
    if(pos<0)
    {
        if(suru==1 && mask==0)
            return 1;
        return 0;
    }
    ll &res = dp[pos][mask][suru][choto][boro][Base];
    if(res != -1 && choto && boro)
        return res;
    int lo = 0, hi = b-1;
    if(choto == 0)
        hi = B[pos] - '0';
    if(boro == 0)
        lo = A[pos] - '0';
    res = 0;
    for(int i=lo; i<=hi; i++)
    {
        int nw_mask = mask;
        if(suru| (i>0))
            nw_mask = mask ^ (1<<i);
        res += fun(pos-1,nw_mask, suru|(i>0), choto|(i<hi), boro|(i>lo),Base);
    }
    return res;
}

string funs(ll a, ll b)
{
    string s;
    while(a!=0)
    {
        int now = a%b;
        now += '0';
        s += now;
        a /= b;
    }
    return s;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&b);
        ll aa,bb;
        scanf("%lld %lld",&aa,&bb);
        A = funs(aa,b);
        B = funs(bb,b);
        while(A.size()<B.size())
            A.push_back('0');
        sz = A.size();
        ll res = fun(sz-1,0,0,0,0,b);
        printf("%lld\n",res);
    }
}
