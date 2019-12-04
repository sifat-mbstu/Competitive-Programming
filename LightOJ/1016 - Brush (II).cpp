///Accepted
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind =0;
    scanf("%d",&TC);
    while(TC--){
    int n,w;
    scanf("%d %d",&n, &w);
    int y[n+1];
    for(int i=0; i<n; i++)
    {
        int v;
        scanf("%d",&v);
        scanf("%d",&y[i]);
    }
    sort(y,y+n);
    int cur = y[0]+w;
    int cnt = 1;
    for(int i=0; i<n; i++)
    {
        if(y[i]<=cur)
        {
            continue;
        }
        else
        {
            cur = y[i]+w;
            i--;
            cnt++;
        }
    }
    printf("Case %d: %d\n",++ind,cnt);
    }
}
