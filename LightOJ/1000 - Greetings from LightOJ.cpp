#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);
        if(a>10){a=10;}
        if(b>10){b=10;}
        printf("Case %d: %d\n",i,a+b);
    }
    return 0;
}
