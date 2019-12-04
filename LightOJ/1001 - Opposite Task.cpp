#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b,i,N;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        if(N==0){ a = b =0;}
        else {a = N/2; b = N-a;}
        printf("%d %d\n",a,b);
    }
    return 0;
}
