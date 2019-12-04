#include<bits/stdc++.h>
using namespace std;
#define Max 1010
vector<int>G[Max];
vector<int> Green;
vector<int> Blue;
int ara[Max][Max];
int loop;

int check_bipartite(){
    int Bipartite;
for(int i=0;i<Green.size(); i++)
    {
        for(int j=0; j<Green.size(); j++)
        {
            if(ara[Green[i]][Green[j]] == 1){
                Bipartite = 0;
                return 0;
            }
        }
    }
    for(int i=0;i<Blue.size(); i++)
    {
        for(int j=0; j<Blue.size(); j++)
        {
            if(ara[Blue[i]][Blue[j]] == 1){
                Bipartite = 0;
                return 0;
            }
        }
    }
    return 1;
}
int bfs(int n, int source)
{
     int Bipartite;
    vector<int>V1,V2;
    V1.push_back(source);
    int taken[Max]= {0};
    int taken1=1;
    Green.push_back(source);
    for(loop=1; loop<n; loop++)
    {
        for(int i=0; i<V1.size(); i++)
        {
            int u=V1[i];
            for(int j=0; j<G[u].size(); j++)
            {
                int v=G[u][j];

                if(!taken[v])
                {
                    if(loop % 2 == 0){Green.push_back(v);}
                    else {Blue.push_back(v);}
                    taken[v]=1;
                    V2.push_back(v);
                }
            }
        }
        if(V2.empty())
        {
            break;
        }
        else
        {
            V1.clear();
            V1=V2;
            V2.clear();
        }
        Bipartite = check_bipartite();
        if(Bipartite == 0) return 0;
    }
    return 1;
}
int main()
{
     int Bipartite;
   // freopen("output.txt","w",stdout);
    int N, E, source;
    while(cin >> N)
    {
    if(!N) break;
     cin >> E;
     memset(ara, 0 , sizeof(ara));
     for(int i=0; i<Max; i++) G[i].clear();
     Green.clear();
     Blue.clear();
    for(int i=1; i<= E; i++)
    {
        int x , y;
        cin >> x >> y;
        if(i==1) source = x;
        G[x].push_back(y);
        G[y].push_back(x);
        ara[x][y] = 1;
        ara[y][x] = 1;
    }
    int n1, n2;
    int res = bfs(N, source);

    if(res) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
    }
}
