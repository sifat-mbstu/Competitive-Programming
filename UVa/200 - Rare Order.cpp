#include<bits/stdc++.h>
using namespace std;
#define mx 100
#define vi vector <int>
vi G[mx], ans;
int ache_naki[mx],visit[mx];
void dfs(int u)
{
    visit[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!visit[v])
        {
            dfs(v);
        }
    }
    ans.push_back(u);
}
int main()
{
    string s1,s2;
    cin >> s1;

    while(cin >> s2 && s2 != "#")
    {
        for(int i=0; i<s1.size() && i<s2.size(); i++)
        {
            if(s1[i]!=s2[i])
            {
                ache_naki[s1[i]-'A'] = ache_naki[s2[i]-'A'] = 1;
                G[s1[i]-'A'].push_back(s2[i]-'A');
                break;
            }
        }
        s1 = s2;
    }
    for(int i=0; i<26; i++)
    {
        if(!visit[i]&& ache_naki[i])
        {
            dfs(i);
        }
    }
    for(int i=ans.size()-1; i>=0; i--)
    {
        char c = ans[i]+'A';
        printf("%c",c);
    }
    cout << endl;
    return 0;
}
