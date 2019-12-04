#include<bits/stdc++.h>
using namespace std;
int ara[200];
int main()
{
    int TC, T, i, j, k, x;
    bool flag ;
    scanf("%d",&TC);
    for(i=1; i<=TC; i++)
    {
        flag = 1;
        memset(ara, 0, sizeof(ara));
        scanf("%d",&T);
            for(j=0; j<T*T; j++)
            {
                scanf("%d", &x);
                ara[x]++;
                if(ara[x] > T)
                {
                    //printf("ara[x] = %d\n",ara[x]);
                    flag = 0;
                }
            }
    if(!flag){printf("Case %d: no\n", i);}
    else{printf("Case %d: yes\n", i);}
    }
}
