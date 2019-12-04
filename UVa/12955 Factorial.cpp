#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long N,res,fac,i,cnt,j;
    while(scanf("%llu",&N)==1)
    {
        fac = 1;
        cnt = 0;
        for(j=10; j>0; j--)
        {
            fac = 1;
            for(i=1; i<=j; i++)
            {
                fac = fac * i;
            }
            while(fac <= N)
            {
                N -= fac;
                cnt++;
            }
            if(N==0)
            {
                break;
            }
        }
        printf("%llu\n",cnt);
    }
}
