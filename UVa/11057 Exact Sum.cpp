#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,ara[10000],price,num,res1,res2,i,j,sub,loc,t;
    while(scanf("%lld",&N)==1)
    {
        t=1;
        for(i=0; i<N; i++)
        {
            scanf("%lld",&ara[i]);
        }
        scanf("%lld",&price);
        sort(ara,ara+N);
        num = price / 2;
        for(i=0; i<N; i++)
        {
            if(num <= ara[i])
            {
                loc=i;
                break;
            }
        }
        //printf("ara[loc] = %lld\n",ara[loc]);
        for(i=loc; i >= 0; i--)
        {
            sub = price - ara[i];
            //  printf("sub = %lld\n",sub);
            for(j=0; j < N ; j++)
            {
                if((sub==ara[j]) && (j!=i))
                {
                    res1=ara[i];
                    res2=ara[j];
                    t=0;
                    break;
                }
            }
            if(t==0)
            {
                break;
            }
        }
        if(res1>=res2)
        {
            printf("Peter should buy books whose prices are %lld and %lld.\n\n",res2,res1);
        }
        else
        {
            printf("Peter should buy books whose prices are %lld and %lld.\n\n",res1,res2);
        }
    }
    return 0;
}
