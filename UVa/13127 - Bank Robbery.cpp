#include<bits/stdc++.h>
#define mx 1001
#define INF 101010
using namespace std;
vector<int>G[mx];
vector<int>cost[mx];
int d[mx], Bank[mx], P_S[mx];
vector <int> vec[mx], Res_bank;
struct data
{
    int city,dist;
    data(int a,int b)
    {
        city = a;
        dist = b;
    }
    bool operator < (const data& p) const
    {
        return dist>p.dist;
    }
};

void Dijkstra(int S,int node)
{
    int i,j,u,v;
    for(j=0; j<=mx; j++)
        d[j] = INF;
    priority_queue<data>Q;
    Q.push(data(S,0));
    d[S] = 0;
    while(!Q.empty())
    {
        data top = Q.top();
        //cout << top.city << "top\n";
        Q.pop();
        u = top.city;
        for(i=0; i<G[u].size(); i++)
        {
            v = G[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v] = d[u]+cost[u][i];
                Q.push(data(v,d[v]));
            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int node,edge,i,j,k,l,m,x,y,z,S,E,TC, B, PS;
    while(scanf("%d %d %d %d",&node,&edge,&B,&PS)==4){

    int Res[mx];
        for(i=0; i<edge; i++)
        {
            cin >> x >> y >> z;

            G[x].push_back(y);
            G[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        int MAX = 0;
        for(i=0; i<B; i++)
            cin >> Bank[i];
        for(i=0; i<PS; i++)
            cin >> P_S[i];
        if(PS != 0){
        for(i=0; i<B; i++)
        {
            //memset(d,0,sizeof(d));
            Dijkstra(Bank[i], node);
            for(j=0; j<PS; j++)
            {
                vec[i].push_back(d[P_S[j]]);
            }
            sort(vec[i].begin(), vec[i].end());
            Res[i] = vec[i][0];
            MAX = max(MAX, Res[i]);
        }

        for(i=0; i<B; i++)
        {
            if(Res[i] == MAX)
            {
                Res_bank.push_back(Bank[i]);
            }
        }
        sort(Res_bank.begin(), Res_bank.end());

        if(MAX == INF) cout << Res_bank.size() << " *" << endl;
        else cout << Res_bank.size() << " " << MAX << endl;
        }
        if(PS == 0){ sort(Bank, Bank+B);
        cout << B << " *" << endl;
        if(B > 0) cout << Bank[0];
        for(i=1;i<B;i++)
            cout <<" " << Bank[i];

        cout << endl;
            for(l =0; l<mx; l++)
        {
            Res[i] = 0; G[l].clear(); cost[l].clear(); vec[l].clear();
        }
        //if(vec[0].empty()){cout << "YES";}
        Res_bank.clear();
        }
        else{
        cout << Res_bank[0];
        for(i=1; i<Res_bank.size(); i++) cout << " " << Res_bank[i];
        cout << endl;
        //memset(d,0,sizeof(d));
        for(l =0; l<mx; l++)
        {
            Res[i] = 0; G[l].clear(); cost[l].clear(); vec[l].clear();
        }
        //if(vec[0].empty()){cout << "YES";}
        Res_bank.clear();
        }
}
    return 0;
}
