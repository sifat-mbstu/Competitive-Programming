#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long i,N,m;
    while(scanf("%llu",&N)==1)
    {
        if(N==0){break;}
    double test=0;
    double sq = sqrt(N);
    test=sq-floor(sq);

    if(test){printf("no\n");}
    else{printf("yes\n");}
    }
    return 0;
}
