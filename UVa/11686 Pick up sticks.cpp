#include<bits/stdc++.h>
using namespace std;

#define M 1000000
vector<int> ans, depends[M];
int taken[M];
int check[M];
int cycle = 0;
void reset()
{
    cycle =0;
    for(int i=0; i<M; i++)
    {
        check[i] = 0;
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

void dfs( int p )
{
    if(check[p]==2 || cycle)
    {
        return;
    }
    if(check[p]==1)
    {
        cycle = 1;
        return;
    }
    check[p] = 1;
    for(int i=0; i<depends[p].size(); i++)
    {
        dfs(depends[p][i]);
    }
    check[p] = 2;
}

int main()
{
    freopen("out.txt","w",stdout);
    int n,e;
    int TC;
    cin >> TC;
    while(TC--)
    {
        cin >> n >> e;

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
        int cnt = 0;
        if(cycle) cout << "IMPOSSIBLE\n";
        else
        {
            for(int i=ans.size()-1; i>=0; i--)
            {
                int val = ans[i];
                if(!check[val])
                {
                    cnt++;
                    dfs(val);
                }

            }
        }
        cout << cnt << endl;
    }
    return 0;
}
