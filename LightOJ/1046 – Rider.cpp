#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define pii pair<int,int>
#define piii pair<pii,int>
#define FOR(I) for(int I = 0; I < 8; I++)
#define fs  first
#define sc  second
#define mp make_pair
#define mx 15
int fx[]= {1,2,2,-1,-1,-2,-2,1};
int fy[]= {-2,1,-1,2,-2,1,-1,2};
int ind;
int row, col;
int level[101][101][101];
bool check(int x,int y)
{
    if(x>=0 && y>=0 && x<row && y<col && level[ind][x][y]==inf)
    {
        return 1;
    }
    return 0;
}
void bfs(int sx, int sy)
{
    level[++ind][sx][sy] = 0;
    queue <pii> Q;
    Q.push(mp(sx,sy));
    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();

        FOR(i)
        {
            int tx = top.fs + fx[i];
            int ty = top.sc + fy[i];
            if(check(tx,ty))
            {
                level[ind][tx][ty] = level[ind][top.fs][top.sc] + 1;
                Q.push(mp(tx,ty));
            }
        }
    }
}

int main()
{
    int tc,Ind =0;
    cin >> tc;
    while(tc--)
    {
        for(int i=0; i<101; i++)
        {
            for(int j=0; j<101; j++)
            {
                for(int k=0; k<101; k++)
                {
                    level[i][j][k] = inf;
                }
            }
        }
        string s[101];
        cin >> row >> col;
        for(int i=0; i<row; i++)
        {
            cin >> s[i];
        }
        ind = -1;
        map <int,pii> Map;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(s[i][j]!='.')
                {
                    int val = s[i][j] - '0';
                    bfs(i,j);
                    Map[ind] = mp(i,j);
                }
            }
        }
        int Min = inf;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int Sum = 0;
                for(int k = 0; k<=ind; k++)
                {
                    int Val = s[Map[k].fs][Map[k].sc] - '0';

                    if(level[k][i][j]== inf)
                    {
                        Sum = inf;
                        break;
                    }
                    int cur = level[k][i][j];
                    Sum += ceil((double)cur/(double)Val);
                }
                Min = min(Min,Sum);
            }
        }
    if(Min == inf) Min = -1;
        printf("Case %d: %d\n",++Ind,Min);
    }
}
