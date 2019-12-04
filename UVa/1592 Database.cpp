#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>
#define vi vector<int>
int n,m;
vs vec[10010];
map <string, vi> Mp[20];

int dekhi(int x, int y, int j)
{
    for(int i=0; i<m; i++)
    {
        if(i==j)continue;
        if(vec[x][i]==vec[y][i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d %d",&n, &m)==2){
    getchar();
    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin,s);
        string now="";
        for(int j=0; j<s.size(); j++)
        {
            if(s[j]==',')
            {
                vec[i].push_back(now);
                now ="";
            }
            else now += s[j];
        }
        vec[i].push_back(now);
    }
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {

            Mp[j][vec[i][j]].push_back(i);
        }
    }

    bool yes = 0;
    int c1,c2,r1,r2;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            int sz = Mp[j][vec[i][j]].size();
            if(sz>=2)
            {
                vi v = Mp[j][vec[i][j]];
                for(int x=0; x<v.size(); x++)
                {
                    for(int y=x+1; y<v.size(); y++)
                    {

                        int val = dekhi(v[x],v[y],j);
                        if(val!=-1)
                        {
                            yes = 1;
                            c1 = min(val,j);
                            c2 = max(val,j);
                            r1 = min(v[x],v[y]);
                            r2 = max(v[x],v[y]);
                            break;
                        }
                    }
                    if(yes)break;
                }
                if(yes)break;
            }
            if(yes)break;
        }
        if(yes)break;
    }

    if(yes)
    {
        cout << "NO" << endl;
        cout << r1+1 << " " << r2+1 << endl;
        cout << c1+1 << " " << c2+1 << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    for(int i=0; i<=n; i++)vec[i].clear();
    for(int i=0; i<=m; i++)Mp[i].clear();
    }
}
