///Accepted
#include<bits/stdc++.h>
using namespace std;
long int GCD,LCM;
long int LCMF(int u,int v)
{
    long int a;
    while(a!=0)
    {
        a = u % v;
        u = v;
        v = a;
    }
    return (GCD*LCM)/u;
}
int main()
{
    long int i,j,a,b,k,test,t;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld %ld",&GCD,&LCM);
        if(GCD>LCM) {t = 0;}
        else
        {
            for(i=GCD; i<=LCM; i+=GCD)
            {
                t=0 , a = i;
                b = (GCD*LCM)/a;
                if((b%GCD==0) &&(LCM %a==0) && (LCM%b==0))
                {
                    k = LCMF(a,b);
                    //printf("k = %ld\n",k);
                    if(k==b) {t = 1; break;}
                    else {t = 0;}
                }
            }
        }
        if(t==0){ printf("-1\n"); }
        else { printf("%ld %ld\n",a,b); }
    }
    return 0;
}
