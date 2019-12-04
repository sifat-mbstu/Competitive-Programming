#include<bits/stdc++.h>
using namespace std;
#define lolo long long
int main()
{
    /*freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);*/
    lolo TC,i,j,k,Mat[20000],N,M,x;
    char c,p,q;
    scanf("%lld",&TC);
    for(x=1;x<=TC;x++)
    {
    getchar();
    scanf("N = %lld",&N);
    /*scanf("%c %c %c",&c,&p,&q);
    scanf("%lld",&N);*/
    //printf("%c %c %c",c,c,c);
    //printf("%lld\n",N);
    N = N*N;
    M = 1;
    for(i=0;i<N;i++)
    {
            scanf("%lld",&Mat[i]);
            if(Mat[i] < 0){M=0;}
    }
    j=N-1;
    for(i=0;i <= N/2;i++,j--)
    {
        if(Mat[i] != Mat[j])
        {
             M = 0; break;
        }
    }
    if(M) { printf("Test #%lld: Symmetric.\n",x); }
    else { printf("Test #%lld: Non-symmetric.\n",x); }
    }
    return 0;
}
