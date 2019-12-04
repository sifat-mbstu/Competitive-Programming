
#include<bits/stdc++.h>
using namespace std;

#define M 1000000
vector<int> ans, depends[M];
int taken[M];
int cycle = 0;
void reset()
{
    cycle =0;
    for(int i=0; i<M; i++)
    {
        taken[i] = 0;
        depends[i].clear();
    }
    ans.clear();
}
void take( int p )
{
//    cout << "p = " << p << "taken " << taken[p] << endl;
//    getchar();
    if(taken[p]==2 || cycle)
    {
//        cout << "Hmm 1";
        return;
    }
    if(taken[p]==1)
    {
//                cout << "Hmm 2";
        cycle = 1;
        return;
    }
    taken[p] = 1;
    for(int i=0; i<depends[p].size(); i++)
    {
//          printf("depend = %d\n",depends[p][i]);
        take(depends[p][i]);
    }
    taken[p] = 2;
    ans.push_back(p);
}

int main()
{
    int n,e;
    while(cin >> n >> e)
    {
        if(!n && !e)break;
        reset();
        for(int i=0; i<e; i++)
        {
            int u,v;
            scanf("%d %d",&u, &v);
            depends[u].push_back(v);
        }
        for(int i=1; i<=n; i++)
        {
            if(!taken[i]) take(i);
        }
        if(cycle) cout << "IMPOSSIBLE\n";
        else
        {
            if(ans.size()>0)cout << ans[ans.size()-1];
            for(int i=ans.size()-2; i>=0; i--)
            {
                printf(" %d", ans[i]);
            }
            cout << endl;
        }
    }
    return 0;
}
