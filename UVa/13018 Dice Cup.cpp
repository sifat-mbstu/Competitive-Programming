#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,i,mini,maxi,l=0;
    while(scanf("%d %d",&N,&M)==2)
    {
        if(l==1)printf("\n");
        mini = min(M,N);
        maxi = (M+N) - mini;
        for(i=mini+1; i<= maxi+1; i++)
        {
            printf("%d\n",i);
        }
        l=1;
    }
}
