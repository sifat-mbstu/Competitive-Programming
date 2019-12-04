#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i;
    double N,M,A,B,X;
    scanf("%d",&T);
    for(i = 1; i<=T ; i++)
    {
        scanf("%lf %lf %lf %lf",&N,&M,&A,&B);
        X = A + B;
        X *= M;
        X = X - (N * A);
        X = X / B;
        if (X >= 0 && X <= 10)
        {
            printf("Case #%d: %.2lf\n",i,X);
        }
        else
        {
            printf("Case #%d: Impossible\n",i);
        }
    }
}
