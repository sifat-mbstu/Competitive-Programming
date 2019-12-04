#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,indegree[1000],arr[1000];
    string Mp[1000];
    vector<int>graph[1000];
    cin>>n;

    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        Mp[i+1] = s;
    }

    for(int i=0; i<1000; i++)
        graph[i].clear();

    memset(indegree, 0,sizeof(indegree));

    while(m--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int a = Mp[s1];
        int b = Mp[s2];
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    cin >> m;
    for(int i=1; i<=m; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            cout <<"==>"<< i << endl;
        }
    }

    int j=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        arr[j++]=u;
        for(int i=0; i<graph[u].size(); i++)
        {
            indegree[graph[u][i]]--;
            if(indegree[graph[u][i]]==0)
            {
                q.push(graph[u][i]);
            }
        }
    }
    for(int i=0; i<j; i++)
        cout<<Mp[arr[i]]<<endl;
}
