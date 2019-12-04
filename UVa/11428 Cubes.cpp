#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    //freopen("input.txt","r",stdin);

    int N,x,y,t;
    while(scanf("%d",&N))
    {
        t = 0;
        if(N==0)
        {
            break;
        }
        for(x = 1; x < 61; x++)
        {
            for(y = 1; y < x; y++)
            {
                if(N ==(x*x*x - y*y*y))
                {
                    printf("%d %d\n",x,y);
                    t = 1;
                    break;
                }
            }
            if(t)
            {
                break;
            }
        }
        if(!t)
        {
            printf("No solution\n");
        }
    }
}
