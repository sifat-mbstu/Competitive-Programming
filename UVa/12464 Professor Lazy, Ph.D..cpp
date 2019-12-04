#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long Alpha,Bita,n,i;
    double res1,res2,res;
    while(scanf("%lld %lld %lld",&Alpha, &Bita, &n)==3){
    if(!Alpha && !Bita && !n) break;
    n = n%5;
    if(n==0)
    {
        res =  Alpha;
    }
    else if (n ==1)
    {
        res = Bita;
    }
    else
    {
        res1 = Alpha;
        res2 = Bita;

        for(i=1 ; i< n; i++)
        {
            res = (1 + res2) / res1;
            res1 = res2;
            res2 = res;
        }
    }
    printf("%.0lf\n",res);
    }
    return 0;
}
