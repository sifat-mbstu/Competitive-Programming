#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define pii pair<int,int>
#define mp make_pair
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
//int fz[] = {0, 1, -1};
int cell[50][50], vis[50][50];
int d[50][50];
int row, col;
string s[50];
map<int,pii> loc;
void bfs(int sx, int sy, char cur)
{
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
        {
            d[i][j] = inf;
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue <pii> q;
    d[sx][sy] = 0;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(tx>=0 && ty>=0 && tx<row && ty<col && s[tx][ty]!= '#' && vis[tx][ty]== 0)
            {
//                cout << tx << " " << ty << endl;
                if(s[tx][ty]>='A' && s[tx][ty]<='Z')
                {
//                    cout << s[tx][ty] << endl;
//                    cout << cur << endl;
                    if(s[tx][ty]<=cur)
                    {
//                       cout << "hmm" << endl;
                        vis[tx][ty] = 1;
                        d[tx][ty] = d[top.first][top.second] + 1;
                        q.push(pii(tx,ty));
                    }
                }

                else
                {
                    vis[tx][ty] = 1;
                    d[tx][ty] = d[top.first][top.second] + 1;
                    q.push(pii(tx,ty));
                }
//                printf("dis = %d\n",d[tx][ty]);
            }
        }
    }
}
int main()
{
    int tc,ind = 0;
    cin >> tc;
    while(tc--)
    {
        loc.clear();
        int x1,x2,y1,y2;
        cin >> row;
        col = row;
        for(int i=0; i<row; i++)
        {
            cin >> s[i];
            for(int j=0; j<col; j++)
            {
                if(s[i][j] <= 'Z' && s[i][j]>='A')
                {
                    int val = s[i][j]-'A';
                    loc[val] = mp(i,j);
                }
            }
        }
        bool poss = 1;
        int sum = 0;
//    cout << loc.size() << endl;
        for(int i=0; i<loc.size()-1; i++)
        {
            bfs(loc[i].first, loc[i].second, i+1+'A');
            int dis = d[loc[i+1].first][loc[i+1].second];
//        cout << dis << endl;
            if(dis ==inf)
            {
                poss = 0;
                break;
            }
            sum += dis;
        }
        if(poss) printf("Case %d: %d\n",++ind,sum);
        else
        {
            printf("Case %d: Impossible\n",++ind);
        }
    }
}
