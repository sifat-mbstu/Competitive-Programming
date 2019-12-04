#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
    int ara_n[32800],ara_m[32800],sum;
    int n,m,i,doomed,j;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0&&m==0)
        {
            break;
        }
        sum=0;
        doomed=1;
        if(m<n)
        {
            doomed=0;
            break;
        }

        for(i=0; i<n; i++)
        {
            scanf("%d",&ara_n[i]);
        }
        sort(ara_n,ara_n+n);

        for(i=0; i<m; i++)
        {
            scanf("%d",&ara_m[i]);
        }
        sort(ara_m,ara_m+m);
        if(n==m)
        {
            for(i=0; i<n; i++)
            {
                if(ara_m[i]>=ara_n[i])
                {
                    sum=sum+ara_m[i];
                }
                else
                {
                    doomed = 0;
                    break;
                }
            }
        }
        else
        {
            doomed=0;
            for(i=0,j=0; i<m; i++)
            {
                if(ara_m[i]>=ara_n[j])
                {
                    sum = sum + ara_m[i];
                    j++;
                }

                if(j==n)
                {
                    doomed=1;
                    break;
                }
            }
        }
        if(doomed)
        {
            printf("%d\n",sum);
        }
        else
        {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}
