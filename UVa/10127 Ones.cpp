#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,one,multi=1,r,n,k;
    while(scanf("%d",&n)==1)
    {
        if(n==1)
        {
            printf("%d\n",n+2);
        }
        else if(n==11)
        {
            printf("%d\n",4);
        }
        else
        {
            k = 1;
            for(i=1; ; i++)
            {
                r = k % n;
                printf("r == %d\n",r);
                if(r == 0)
                {
                    printf("%d\n",i);
                    break;
                }
                k = r*10 + 1;
            }
        }
    }

}
