#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TC, n, ara[10010], c;
    scanf("%d",&TC);
    for(int k=1; k<=TC; k++)
    {
        scanf("%d",&n);
        c = 1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
            if(ara[i] == c)
            {
                c++;
            }
        }
        printf("Case %d: %d\n",k,n - c + 1);
    }
}
