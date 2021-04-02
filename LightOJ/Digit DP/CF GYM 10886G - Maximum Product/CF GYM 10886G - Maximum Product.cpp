#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sz;
string A,B;
ll dp[19][2][2][2];

ll fun(int pos, int choto, int boro, int suru)
{
    if(pos==sz)
    {
        if(suru)return 1;
        return 0;
    }
    ll &ret = dp[pos][choto][boro][suru];
    if(ret!=-1) return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos]-'0';
    ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        if(suru==1 || i>0) ret = max( ret, i*fun(pos+1, choto|(i<hi), boro|(i>lo), suru|(i>0)) );
        else ret = max(ret, fun(pos+1,choto|(i<hi), boro|(i>lo), suru|(i>0)));
    }
    return ret;
}

void path(int pos, int choto, int boro, int suru)
{
    if(pos==sz) return ;
    ll Max = fun(pos,choto,boro,suru);
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    if(boro==0) lo = A[pos]-'0';
    ll ret = 0;
    for(int i=lo; i<=hi; i++)
    {
        if(suru==1 || i>0) ret = max( ret, i*fun(pos+1, choto|(i<hi), boro|(i>lo), suru|(i>0)));
        else ret = max(ret, fun(pos+1,choto|(i<hi), boro|(i>lo), suru|(i>0)));
        if(ret==Max)
        {
            if(suru | i>0)printf("%d",i);
            path(pos+1,choto|(i<hi),boro|(i>lo),suru|(i>0));
            break;
        }
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> A >> B;
    while(A.size() <B.size()) A.insert(A.begin(),'0');
    sz = A.size();
    int res = fun(0,0,0,0);
    path(0,0,0,0);
    printf("\n");
}
