#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC,i,j,len,sum,dif;
    char s1[200],s2[200];
    scanf("%d",&TC);
    for(j=1; j<=TC; j++)
    {
        scanf("%d",&len);
        scanf("%s",&s1);
        scanf("%s",&s2);
        sum = 0;
        for(i=0; i<len; i++)
        {
            dif = fabs(s1[i] - s2[i]);
            if ( dif > 5)
            {
                dif = 10 - dif;
            }
            sum += dif;
        }
        printf("Case %d: %d\n",j,sum);
    }
}
