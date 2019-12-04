#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,T,N,ara[20000],counts;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d ",&N);
    counts = 0;
    for(i=0; i < N; i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=N-1;i>0;i--)
    {
        for(j=i-1;j >= 0; j--)
        {
            if(ara[j] <= ara[i])
            {
                counts++;
            }
        }
    }
    printf("%d\n",counts);
    }
}
