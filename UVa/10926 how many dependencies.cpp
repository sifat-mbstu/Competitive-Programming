#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define M 111
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
    if(taken[p]==2)
    {
//        cout << "Hmm 1";

        return;
    }
    if(taken[p]==1)
    {
//                cout << "Hmm 2";
         ans.push_back(p);
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
int cnt = 0;
int Max = 0;
void dfs( int p, int mark )
{
//    cout << "p - "   << p << endl;
    if(check[p])
    {
        return;
    }
    check[p] = mark;
    cnt++;
    for(int i=0; i<depends[p].size(); i++)
    {
        dfs(depends[p][i],mark);
    }
}

int main()
{
//    freopen("out.txt","w",stdout);
    int n,e,ind=0;
    while(cin >> n)
    {
        if(!n) break;
        Max = 0;
        e = n;
        reset();

        for(int i=1; i<=e; i++)
        {

            int val;
            scanf("%d",&val);
            while(val--){
                    int v;
            scanf("%d",&v);
            depends[i].push_back(v);
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(!taken[i]) take(i);
        }

//        if(cycle) cout << "IMPOSSIBLE\n";
//        else
//        {
            int res = inf;
            int mark = 0;
            for(int i=ans.size()-1; i>=0; i--)
            {
                memset(check, 0, sizeof(check));
                cnt = 0;
                int val = ans[i];
                if(!check[val])
                {
                    dfs(val,++mark);
                    if(cnt >= Max)
                    {
                        if(cnt == Max)
                        {
                            res = min(res,val);
                        }
                        else
                        {
                            res = val;
                        }
                        Max = cnt;
                    }
                }

            }
//        }
//        printf("Case %d: %d\n",++ind,res);
        cout <<res << endl;
    }
    return 0;
}
