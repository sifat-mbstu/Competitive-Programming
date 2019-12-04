#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,i,d,ara[10],x,j,a,test,counts;
    while(scanf("%d %d",&N,&M)==2)
    {
        counts=0;
        for(i=N; i<=M; i++)
        {
            //printf("%d",i);
            j=i;
            test=0;
            for(x=0; x<10; x++)
            {
                ara[x]=0;
            }
            while(j!=0)
            {
                a=j%10;
                ara[a]++;
                j=j/10;
            }
            for(x=0; x<10; x++)
            {
                if(ara[x]>1)
                {
                    test=1;
                    break;
                }
            }
            if(test)
            {
                counts++;
            }
        }
        printf("%d\n",M-N-counts+1);
    }
    return 0;
}
