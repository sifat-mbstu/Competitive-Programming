#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,sum,lim,win,N,M[100],L[100],TC;
    scanf("%d",&TC);
    for(k=1;k <= TC; k++){
    scanf("%d %d", &N, &lim);
    sum = 0;
    win = 1;
    for(i=0;i<N;i++)
    {
        scanf("%d",&M[i]);
        sum += M[i];
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&L[i]);
    }
    if(sum > lim)
    {
        win = 0;
    }
    else{
        for(i=0;i<N;i++)
        {
            if(M[i] > L[i])
            {
                win = 0;
                break;
            }
        }
    }
    if(win){printf("Case %d: Yes\n",k);}
    else{printf("Case %d: No\n",k);}
    }
}
