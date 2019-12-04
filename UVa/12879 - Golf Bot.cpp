#include<bits/stdc++.h>
using namespace std;
#define mx 200010
int hole[mx], bot[mx], cnt[mx],chq[mx];
int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        memset(hole,0,sizeof(hole));
        memset(bot,0,sizeof(bot));
        memset(cnt,0,sizeof(cnt));
        memset(chq,0,sizeof(chq));
        for(int i=0; i<n; i++)
        {
            int val;
            scanf("%d",&val);
            cnt[val]++;
        }
        int j=0;
        for(int i=0; i<mx; i++)
        {
            if(cnt[i])
            {
//            cout <<"i = " << i << endl;
                bot[j] = i;
//            printf("bot[%d] = %d\n",j,bot[j]);
                j++;
            }
        }
        n = j;
//    for(int i=0; i<n; i++)
//    {
//        printf("bot[%d] = %d\n",i,bot[i]);
//    }
        cnt[0] = 1;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&hole[i]);
        }
        sort(hole,hole+m);
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int k=0; k<n; k++)
            {
                if(bot[k]<=hole[i])
                {
                    if(cnt[hole[i]-bot[k]])
                    {
                        ans++;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
}
