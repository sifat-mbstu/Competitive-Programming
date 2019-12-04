#include <bits/stdc++.h>
using namespace std;
int DP[220];
int f(int N)
{
    if(N==2){ return 1; }
    else if(N<=1){return 0;}
    if(DP[N]!=-1){return N/3 + DP[N];}
    else
    {
            DP[N] = f(N/3 + N%3);
            return N/3 + DP[N];
    }
}
int main()
{
    int rem,N,i;

    for(i=0;i<=210;i++)
    {
        DP[i]=-1;
    }
    while(scanf("%d",&N)==1){
    int res = f(N);
    cout << res+N << endl;
    }
}
