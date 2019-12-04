#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,cnt,fin_cnt,goal;
    while(scanf("%d %d",&n,&m)==2){
    fin_cnt = 0;
    for(i=0; i<n; i++)
    {
        cnt = 0;
        for(j =0; j<m ;j++)
        {
            scanf("%d",&goal);
            if(goal >0){ cnt++;}
        }
        if(cnt == m) {fin_cnt++;}
    }
    printf("%d\n",fin_cnt);
    }
}
