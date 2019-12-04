#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100][100] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
    int Brown[10], Green[10], Clar[10],sum[10],i,j,mini,index;
    while(scanf("%d %d %d",&Brown[0],&Green[0],&Clar[0])==3){
    scanf("%d %d %d",&Brown[1],&Green[1],&Clar[1]);
    scanf("%d %d %d",&Brown[2],&Green[2],&Clar[2]);
    memset(sum,0,sizeof(sum));
    mini = 2114712300;
    for(i=0;i<6;i++)
    {
        for(j=0;j<3;j++)
        {
            if(str[i][j] =='B') {sum[i] += Green[j] + Clar[j]; }
            else if(str[i][j] =='G') {sum[i] += Brown[j] + Clar[j]; }
            else if(str[i][j] =='C') {sum[i] += Brown[j] + Green[j]; }
        }
        if(mini > sum[i]){mini = sum[i]; index = i;}
    }
    printf("%s %d\n",str[index],mini);
}
}
