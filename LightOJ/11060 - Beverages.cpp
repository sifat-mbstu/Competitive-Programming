#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b;
    scanf("%d",&n);
    string Drink[10000];
    map <string,int> Mp;
    vector<int> G[10100];
    queue <int> Q;
    int indeg[10100];

    memset(indeg,0,sizeof(indeg));

    for(int i=1; i<=n; i++)
    {
        cin >> Drink[i];
        Mp[Drink[i]] = i;
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        a = Mp[s1];
        b = Mp[s2];
        G[a].push_back(b);
        indeg[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(!indeg[i])
        {
            Q.push(i);
        }
    }
    int res[10001];
    int ind = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        res[ind++] = u;
//            res.push_back(u);
        for(int i=0; i<G[u].size(); i++)
        {
            indeg[G[u][i]]--;
            if(!indeg[G[u][i]]) Q.push(G[u][i]);
        }
    }
    cout << Drink[res[0]];
    //      printf("%d",res[0]);
    for(int i=1; i<ind; i++)
    {
        cout << " " << Drink[res[i]];
//            printf(" %d",);
    }
    printf("\n");
}
