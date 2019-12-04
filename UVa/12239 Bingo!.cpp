#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> myset;
    int N,C,i,res[300],j,dif;
    int ar[100];
    while(scanf("%d %d",&N,&C) == 2){
    if(N == 0 && C == 0){ break;}
    memset(res, 0 , sizeof(res));
    for(i=0;i<C;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<C;i++)
    {
        for(j=0;j<C;j++)
        {
            dif = abs(ar[i]-ar[j]);
            if(dif <= N) myset.insert(dif);
        }
    }
    int bingo = 1;
 /*   for(i=0;i<N;i++)
    {
        if(res[i] != 1)
        {
            bingo = 0;
            break;
        }
    }*/


    if(myset.size() == N+1){printf("Y\n");}
    else{printf("N\n");}
    }
}
