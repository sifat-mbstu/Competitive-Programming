#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
string cell[100];
int vis[100][100];
int row, col;
int bfs(int sx, int sy)
{
    int cnt = 1;
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if((tx>=0 && ty>=0 && tx<row && ty<col && vis[tx][ty]== 0) && (cell[tx][ty] != '#') )
            {
                ++cnt;
                vis[tx][ty] = 1;
                q.push(pii(tx,ty));
            }
        }
    }
    return cnt;
}

int main()
{
    int TC, ind = 0;
    cin >> TC;
    while(TC--)
    {
        for(int i=0; i<100; i++) cell[i].clear();
        int x1=-1,x2,y1,y2;
        cin >> col >> row;

        for(int i=0; i<row; i++)
        {
            cin >> cell[i];
            for(int j=0; j<col && x1==-1 ; j++)
                if (cell[i][j] == '@')
                {
                    x1 = i;
                    y1 = j;
                }
        }
        printf("Case %d: %d\n",++ind,bfs(x1,y1));
    }
}
