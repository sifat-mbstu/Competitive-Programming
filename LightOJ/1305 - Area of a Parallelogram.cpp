#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX/3
#define pi acos(-1.0)

#define pii pair<int,int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

///====================================================
/// Sieve Method
 //-> all primes are stored in 'primes' vector
 //-> 'ara' indicate whether a number is prime or not
/**

#define ll long long
#define N  100000010
#define sq 10000
vector <long> primes;
long long ara[N];
void sieve()
{
    ll i,j;
    primes.push_back(2);
    for(i=0;i<N;i++)
    {
        ara[i] = 0;
    }
    for(i=3;i<sq;i+=2)
    {
        if(ara[i]==0)
        {
            primes.push_back(i);
            for(j=i*i;j<=N; j += (2*i))
            {
                ara[j] = 1;
            }
        }
    }
    for(i=sq+1; i<N; i+=2)
    {
        if(ara[i]==0)
            primes.push_back(i);
    }
}
*/
//********************************************************


/// 1D BFS in QUEUE

   //->initially 'level[]' all value should be infinity
   //->initially 'vis[]' all value should be 0
   //-> 'G'  is a 2D vector (the adjacency list)
///=================================================
/**

#define mx 1000000
vector < int> G[1000];
queue <int> Q;
int level[mx];// = {inf};
void BFS(int source)
{
    Q.push(source);
    level[source] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        //cout << u << endl;
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            //cout << v << endl;
            if(level[v] == inf)
            {
                level[v] = level[u] + 1;
                Q.push(v);
//                cout << "level[" <<v << "] = " << level[v] << endl;
            }
        }
//        cout << endl;
    }
}

*/
///************************************************************

/// 2D BFS in Queue
    //-> Here the Direction Array is for go (4 direction) up, down, left, right
    //->initially 'd[]' all value should be 0
   //->initially 'vis[]' all value should be 0
///====================================================
/**
int fx[] = {1 , -1 , 0 , 0};
int fy[] = {0 , 0 , 1 , -1};
//int fz[] = {0, 1, -1};
int vis[50][50];
int d[50][50];
int row, col;
void bfs(int sx, int sy)
{
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
            if(tx>=0 && ty>=0 && tx<row && ty<col && vis[tx][ty]== 0)
            {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pii(tx,ty));
            }
        }
    }
}
*/
///*******************************************************************************
int main()
{
    int TC, ind =0;
    cin >> TC;

    while(TC--)
    {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x4 = x1 + x3 - x2;
        y4 = y1 + y3 - y2;
        int area = (x2*y3 - x3*y2) + (x3*y4 - x4*y3) + (x4*y1 - x1*y4)+(x1*y2 - x2*y1);
        if(area < 0){area *= (-1);}
        area /= 2;
        printf("Case %d: %d %d %d\n",++ind, x4, y4, area);
    }

}

