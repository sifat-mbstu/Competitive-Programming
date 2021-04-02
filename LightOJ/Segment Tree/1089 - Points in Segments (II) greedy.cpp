///AC
#include<bits/stdc++.h>
using namespace std;
#define mx 200010
int main()
{
    int TC,cas=0;
    scanf("%d",&TC);
    while(TC--)
    {
        vector<int> x,y;
        int n,q;
        scanf("%d %d",&n, &q);
        for(int i=0; i<n; i++)
        {
            int v1,v2;
            scanf("%d %d",&v1, &v2);
            x.push_back(v1);
            y.push_back(v2);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        printf("Case %d:\n",++cas);
        for(int i=0; i<q; i++)
        {
            int v;
            scanf("%d",&v);
            int id1 = upper_bound(x.begin(),x.end(),v)-x.begin();
            int id2 = upper_bound(y.begin(),y.end(),v-1)-y.begin();
            int ans = id1-id2;
            printf("%d\n",ans);
        }

    }
}
