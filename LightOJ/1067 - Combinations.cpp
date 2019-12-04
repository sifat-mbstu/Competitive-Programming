#include<stdio.h>
long long MOD=1000003;
long long f[1000005];
long long mod(long long b,long long p)
{
    if(p==1)
        return b;
    if(p%2==1)
        return(mod(b,p-1)*b)%MOD;
    else
    {
        long long res=mod(b,p/2);
        return (res*res)%MOD;
    }
}
int main()
{
    long long t,n,r,s,res,no=0;
    scanf("%lld",&t);
    f[1]=1;
    for(long i=2;i<1000001;i++)
    f[i]=(i*f[i-1])%MOD;
    while(t--)
    {
        scanf("%lld%lld",&n,&r);
            if(n<r)
            {
                 printf("Case %d: 0\n",++no);
                 continue;
            }
            else if(n==r||r==0)
            {
                printf("Case %d: 1\n",++no);
                continue;
            }
        s=((f[n-r]%MOD)*(f[r]%MOD))%MOD;
        printf("Case %lld: %lld\n",++no,(f[n]*mod(s,MOD-2))%MOD);

    }
    return 0;
}
