#include<bits/stdc++.h>
using namespace std;
#define ll long long
int sz;
string A,B,A1,B1;

ll dp[20][2][1024][1024];

ll fun(int pos, int suru, int mask1,int mask2, int choto) {
    if(pos==sz)
    {
        for(int i=0; i<10; i++)
        {
            if(!(mask2&(1<<i)))continue;
            if(i%2==0 && !(mask1&(1<<i))) return 0;
            if(i%2==1 && (mask1&(1<<i))) return 0;
        }
        return 1;
    }

    ll &ret = dp[pos][choto][mask1][mask2];
    if(ret!=-1 && choto)return ret;
    int lo = 0, hi = 9;
    if(choto==0) hi = B[pos]-'0';
    ret = 0;

    for(int i=lo; i<=hi; i++)
    {
        int nmsk1=mask1;
        int nmsk2=mask2;
        if(suru|i>0)
        {
            nmsk1 = mask1 ^ (1<<i);
            nmsk2 = mask2 | (1<<i);
        }
        ret += fun(pos+1,suru|i>0, nmsk1,nmsk2, choto|(i<hi));
    }
    return ret;
    
}

int main()
{
    ll n,a,b;
    scanf("%lld",&n);
    memset(dp,-1,sizeof(dp));
    while(n--)
    {
        cin >> a >> b;
        a--;
        char st[50];
        sprintf(st,"%lld",a);
        A1=st;
        sprintf(st,"%lld",b);
        B1=st;
        while(A1.size()<B1.size()) A1.insert(A1.begin(),'0');
        while(A1.size()<19)
        {
            A1.insert(A1.begin(),'0');
            B1.insert(B1.begin(),'0');
        }
        sz = A1.size();
        B = A1;
        ll res1 = fun(0,0,0,0,0);
        B = B1;
        ll res2 = fun(0,0,0,0,0);
        ll res = res2-res1;
        printf("%lld\n",res);
    }
    
}
