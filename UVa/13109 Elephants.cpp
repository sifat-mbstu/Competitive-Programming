#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC,M,W,a[100010],i,j,sum;
    scanf("%d",&TC);
    while(TC--)
    {
        scanf("%d",&M);
        scanf("%d",&W);
        sum = 0;
        for(i=0; i<M; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+M);
        i = 0;
        for(i=0; i<M; i++)
        {
            sum = sum + a[i];
            if(sum > W)
            {
                break;
            }
        }
        printf("%d\n",i);
    }
}
