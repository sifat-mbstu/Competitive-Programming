#include<bits/stdc++.h>
using namespace std;
int cnt, taken[200];
vector <int> G[200];
void dfs(int n)
{
    if(taken[n] ==1)
        return ;
    if(!taken[n]) {
    taken[n] = 1;
    }
    for(int i=0; i<G[n].size(); i++)
    {
        dfs(G[n][i]);
    }
}

int main()
{
    //freopen("output.txt", "w", stdout);
    char c;
    string s;
    int TC, i, k = 0;
    cin >> TC;
    while(TC--){
            if(k) cout << endl;
    int Max = 0;
    for(i=0; i<200; i++) G[i].clear();
    memset(taken, 0 ,sizeof(taken));
    cin >> s;
    int N = s[0] - 'A';
    c = getchar();
    for(i=0; ; i++)
    {
        getline(cin, s);
       // cout << s << endl;
        if(s.empty()) break;
        G[s[0]-'A'].push_back(s[1]-'A');
        G[s[1]-'A'].push_back(s[0]-'A');
    }
    cnt = 0;
    for(i=0; i<=N; i++)
    {
        if(!taken[i])
        {
            cnt++;
            dfs(i);
            //Max = max(Max, cnt);
        }
    }
    cout << cnt << endl;
    k = 1;
    }
}
