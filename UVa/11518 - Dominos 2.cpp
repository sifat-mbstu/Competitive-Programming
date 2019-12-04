#include<bits/stdc++.h>
using namespace std;
#define mx 10010
vector<int>G[mx];
int taken[mx];
int Fall[mx];
vector<int>V1,V2;
int cnt = 0;
void bfs(int n,int source)
{
    V1.push_back(source);
    //if(!taken[source]) {cnt++; taken[source] = 1;}
    for(int loop=1; loop<n; loop++)
    {
        for(int i=0; i<V1.size(); i++)
        {
            int u=V1[i];
            for(int j=0; j<G[u].size(); j++)
            {
                int v=G[u][j];
                if(!taken[v])
                {
                    cnt++;
                    taken[v]=1;
                    V2.push_back(v);
                }
            }
        }
        taken[source] = 1;
        /*for(int i=1; i<=n; i++)
        {
           cout <<i << "== i .... taken = "<< taken[i] << endl;
        }*/
        if(V2.empty())
        {
           // puts("EMPTY");
           V1.clear();
           V2.clear();
            return;
        }
        else
        {
           // puts("");
            V1.clear();
            V1 = V2;
            V2.clear();
        }
    }
}
int main()
{
    int N, E, l, TC;
    cin >> TC;
    while(TC--){
    cin >> N >> E >> l;
    for(int i=0; i<mx; i++){G[i].clear();}
    int res = 0;
    cnt = 0;
    memset(taken, 0 , sizeof(taken));
    for(int i=1; i<= E; i++)
    {
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        //G[y].push_back(x);
    }
    int n1;
    for(int i=0; i<l; i++){
        cin >> n1;
        bfs(N, n1);
    }
    cnt = 0;
    for(int i=1; i<= N; i++)
    {
        if(taken[i]) cnt++;
    }
    cout << cnt << endl;
    }
}
