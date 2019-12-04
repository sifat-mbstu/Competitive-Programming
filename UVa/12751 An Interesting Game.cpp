#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,i,K,X,j,sum,Total,test;
    scanf("%d",&test);
    for(j=1; j<=test; j++)
    {
        sum=0;
        scanf("%d %d %d", &N, &K, &X);
        Total=(N * (N+1))/2;
        //printf("%d",Total);
        for(i=X; i< X+K; i++ )
        {
            sum = sum + i;
        }
        printf("Case %d: %d\n",j,(Total - sum));
    }
    return 0;
}
