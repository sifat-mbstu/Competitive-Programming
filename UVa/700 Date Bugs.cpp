#include<bits/stdc++.h>
using namespace std;
int Mp[10010];
int main()
{
    int n,idx=0;
    while(scanf("%d",&n)==1){
    if(!n)break;
    memset(Mp,0,sizeof(Mp));
    int Max = 0;
    bool flag = 0;
    int res = -1;
    int blnk = 0;
    for(int i=0; i<n; i++)
    {
        int y,a,b;
        scanf("%d %d %d",&y, &a, &b);
        Max = max(Max, a);
        int dif = abs(a-b);
        for(int j=y; j<10000; j+=dif)
        {
            Mp[j]++;
            if(Mp[j]==n && !flag)
            {
                res = j;
                flag = 1;
            }
        }
    }
    if(res!=-1)
    {
        printf("Case #%d:\n",++idx);
        printf("The actual year is %d.\n",res);
    }
    else
    {
        printf("Case #%d:\n",++idx);
        printf("Unknown bugs detected.\n");
    }
        printf("\n");
    }
}
