#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sz;
string A,B;
ll mod = 1000000007;
ll dp[51][2][2][17][17][17];

ll fun(int pos, int choto, int boro, int cnt3, int cnt6, int cnt9)
{
    
    if(cnt3>16 || cnt6>16 || cnt9>16) return 0;
    if(pos==sz)
    {
        if(cnt3>0 && cnt3==cnt6 && cnt6==cnt9) return 1;
        return 0;
    }
    ll &ret = dp[pos][choto][boro][cnt3][cnt6][cnt9];
    if(ret!=-1 && boro ==1 && choto ==1) return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos]-'0';
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        ret = ret % mod + fun(pos+1,choto|(i<hi),boro|(i>lo),cnt3+(i==3),cnt6+(i==6),cnt9+(i==9)) % mod ;
        ret %= mod;
    }
    return ret;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    memset(dp,-1,sizeof(dp));
    while(tc--)
    {
        char s1[52],s2[52];
        scanf("%s %s",&s1,&s2);
        A = s1;
        B = s2;
        while(A.size()!=B.size())
        {
            A.insert(A.begin(),'0');
        }
        
        while(A.size()!=51)
        {
            A.insert(A.begin(),'0');
            B.insert(B.begin(),'0');
        }
        
        sz = 51;
        ll res = fun(0,0,0,0,0,0);
        printf("%lld\n",res);
    }
}
