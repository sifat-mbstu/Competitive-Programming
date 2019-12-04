#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,ara[10],t,N;
    while(scanf("%d",&N)==1){
    t=0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]==N){t++;}
    }
    printf("%d\n",t);
    }
    return 0;
}
