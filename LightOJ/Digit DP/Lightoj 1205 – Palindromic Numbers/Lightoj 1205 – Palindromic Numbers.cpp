#include<bits/stdc++.h>
using namespace std;
#define ll long long
string A,B;
ll dp[19][2][2][19][2];
ll fun(int pos, bool choto, bool suru, int backpos, bool boronisi)
{
    if(pos>backpos)
    {
        if(choto==0 && boronisi) return 0;
        return 1;
    }
    
    ll &ret = dp[pos][choto][suru][backpos][boronisi];
    
    if(ret !=-1)
        return ret;
    
    int lo = 0, hi = 9;
    
    if(choto==0)
        hi = A[pos]-'0';
    
    ret = 0;
    
    for(int i=lo; i<=hi; i++)
    {
        if((suru == 0 && i == 0) || (pos==backpos))
        {
            ret += fun(pos+1, choto | (i<hi),suru|(i>0), backpos,boronisi);
        }
        else
        {
            if(i == A[backpos]-'0')
            {
                ret += fun(pos+1,choto | (i<hi) ,suru|(i>0), backpos-1,boronisi);
            }
            else ret += fun(pos+1,choto | (i<hi),suru|(i>0), backpos-1, i>A[backpos]-'0');
        }
    }
    return ret;
}
int main()
{
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--)
    {
        ll a,b,res1=0,res2=0;
        char s1[50], s2[50];
        scanf("%lld %lld",&a,&b);
        
        if(a>b)swap(a,b);
        a--;
        
        sprintf(s1 , "%lld" ,a);
        sprintf(s2 , "%lld" ,b);
        memset(dp,-1LL,sizeof(dp));
        A = s1;
        
        if(a!=-1)
            res1 = fun(0,0,0,A.size()-1, 0);
        memset(dp,-1,sizeof(dp));
        
        A = s2;
        res2 = fun(0,0,0,A.size()-1, 0);
        ll res = res2-res1;
        printf("Case %d: %lld\n",++idx,res);
    }
}
