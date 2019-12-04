#include <bits/stdc++.h>
using namespace std;
int main()
{
    double sq,N,M;
    int counts,i,Test;
    while (scanf("%lf %lf",&M,&N)==2)
    {
        counts=0;
        if(M==0 && N==0){break;}
        for(i=M; i<=N; i++)
        {
            sq = sqrt(i);
            if(sq - int(sq)==0){counts++;}
        }
        printf("%d\n",counts);
    }
    return 0;
}
