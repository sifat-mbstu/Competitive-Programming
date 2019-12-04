#include<bits/stdc++.h>
using namespace std;
#define qs queue<string>
#define vs vector<string>
#define msvs map<string, vs>
map <string, int> visited;
map <string, string> parent;

void BFS(string source, msvs G)
{
    qs Q;
    Q.push(source);
    visited[source] = 0;
    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++){
        string v = G[u][i];
        if(!visited.count(v))
        {
            visited[v] = visited[u]+1;
            Q.push(v);
            parent[v] = u;
        }
        }
    }
    //cout <<"hmm"  << endl;
}
int main()
{
    bool chq = 1;
    string s1, s2;
    int TC, n,m;
    scanf("%d",&TC);
    while(TC--)
    {
        if(!chq) cout << endl;
        msvs G;
        scanf("%d %d",&n,&m);
        while(n--)
        {
            cin >> s1 >> s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
        }
        while(m--)
        {
            vs V;
            cin >> s1 >> s2;
            visited.clear();
            parent.clear();
            BFS(s1, G);
            V.push_back(s2);
            //cout << "Here" << endl;
            while(1)
            {
                V.push_back(parent[s2]);
                s2 = parent[s2];
                if(s2==s1) break;
                //cout  <<"aaa" << s2 << endl;
            }
            //cout << "ANSSS ==== ";
            for(int i=V.size()-1; i>=0; i--)
            {
                cout << V[i][0];
            }
            cout << endl;
        }
        chq = 0;
    }

}
