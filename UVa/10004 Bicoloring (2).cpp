#include<bits/stdc++.h>
using namespace std;
int ara[220][220],N,E,t,i,n1,n2,j;
int bicolor(int ini)
{
    for(i = ini,j=0; j < N*2 ; i++,j++)
    {
        if(ara[ini][i]==1)
        {
            ara[ini][i]=2;
            return bicolor(i);
        }
        if(ara[ini][i]==2){t=2;break;return 2;}
        if(i==N-1){i=-1;}
    }
}
int main()
{
    long long mini;
    while(scanf("%d",&N)==1){
    mini = 100000000;
    t = 0;
    if(N==0){break;}
    scanf("%d",&E);
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            ara[i][j]=0;
        }
    }
    for(i=0;i<E;i++)
    {
        scanf("%d %d",&n1 ,&n2);
        ara[n1][n2] = 1;
        ara[n2][n1] = 1;
        if(mini > n1){mini = n1;}
        if(mini > n2){mini = n2;}
    }
    bicolor(mini);
    cout << t << endl;
    if(t==2 || (N%2==0)) {printf("NOT BICOLORABLE.\n");}
    else {printf("BICOLORABLE.\n");}
    }
    return 0;
}
