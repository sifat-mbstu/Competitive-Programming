#include<bits/stdc++.h>
using namespace std;
int GCD (int u, int v)
{
    int a;
    while (v!=0)
    {
        a=u%v;
        u=v;
        v=a;
    }
    return u;
}
int main()
{
    int G,i,j,N;
    while(scanf("%d",&N)==1 && N!=0)
    {
        G=0;

        for(i=1; i<N; i++)
            for(j=i+1; j<=N; j++)
            {
                G+=GCD(i,j);
            }
        printf("%d\n",G);
    }
}
