#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,TC,Max,a[350],i,j;
    scanf("%d",&TC);
    for(j=1; j<= TC; j++)
    {
        scanf("%d",&N);
        Max = 0;
        for(i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
            if(Max < a[i])
            {
                Max = a[i];
            }
        }
        printf("Case %d: %d\n",j,Max);
    }
}
