///Accepted
#include<bits/stdc++.h>
using namespace std;
map <string, int> Map;
#define inf INT_MAX/3
int fx[] = {0,0,0,0,1,-1};
int fy[] = {0,0,1,-1,0,0};
int fz[] = {1,-1,0,0,0,0};
int vis[30][30][30];
int level[30][30][30];
string src, des;
void bfs(string s)
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<30; j++)
        {
            for(int k=0; k<30; k++)
            {
                level[i][j][k] = inf;
            }
        }
    }
    int a = s[0] - 'a';
    int b = s[1] - 'a';
    int c = s[2] - 'a';
    if(vis[a][b][c])
    {
        return;
    }
    vis[a][b][c] = 1;
    level[a][b][c] = 0;
    queue <string> q;
    q.push(s);
    while(!q.empty())
    {
        string top = q.front();
        q.pop();
        int P = top[0] - 'a';
        int Q = top[1] - 'a';
        int R = top[2] - 'a';
        string v;
        for(int j=0; j<6; j++)
        {
            int N1 = P + fx[j];
            int N2 = Q + fy[j];
            int N3 = R + fz[j];

            if(N1 < 0)
            {
                N1 += 26;
            }
            if(N2 < 0)
            {
                N2 += 26;
            }
            if(N3 < 0)
            {
                N3 += 26;
            }

            if(N1 > 25)
            {
                N1 -= 26;
            }
            if(N2 > 25)
            {
                N2 -= 26;
            }
            if(N3 > 25)
            {
                N3 -= 26;
            }

            if(!vis[N1][N2][N3])
            {
                level[N1][N2][N3] = level[P][Q][R]+1;
                vis[N1][N2][N3] = 1;
                v += (N1 + 'a');
                v += (N2 + 'a');
                v += (N3 + 'a');
                q.push(v);
                v="";
            }
        }
    }
}
int main()
{
    int tc,ind=0;
    cin >> tc;
    while(tc--)
    {
        string s1,s2,s3;
        cin >> src >> des;
        int n;
        char ch1, ch2, ch3;
        cin >> n;
        getchar();
        memset(vis,0,sizeof(vis));
        while(n--)
        {
            cin >> s1 >> s2 >> s3;
            for(int i=0; i<s1.size(); i++)
            {
                ch1 = s1[i];
                for(int j=0; j<s2.size(); j++)
                {
                    ch2 = s2[j];
                    for(int k=0; k<s3.size(); k++)
                    {
                        ch3 = s3[k];
                        vis[ch1-'a'][ch2-'a'][ch3-'a'] = 1;
//                    printf("in=%c%c%c\n",ch1,ch2,ch3);
                    }
                }
            }
        }
        bfs(src);
//    cout << des[0]-'a' << endl;
//    cout << des[1]-'a' << endl;
//    cout << des[2]-'a' << endl;

        int res = level[des[0]-'a'][des[1]-'a'][des[2]-'a'];
        if(res == inf)
        {
            printf("Case %d: -1\n",++ind);
        }
        else
        {
            printf("Case %d: %d\n",++ind,res);
        }
    }
}
