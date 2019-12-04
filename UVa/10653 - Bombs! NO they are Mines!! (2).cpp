#include<bits/stdc++.h>
using namespace std;
#define mx  10000
pair <int, int> source, destination;
bool Mat[mx][mx];
int vis[mx][mx], cost[mx][mx],R , C;
vector < pair < int, int > > vec[mx];
queue < pair < int,int > > Q;
void reset()
{
    while(!Q.empty())Q.pop();
    for(int i=0; i<mx; i++) vec[i].clear();
    memset(Mat, 0 ,sizeof(Mat));
    memset(cost, 0 ,sizeof(cost));
    memset(vis, 0 ,sizeof(vis));
}

int bfs()
{
    int a, b;
    vis[source.first][source.second] = true;
    cost[source.first][source.second] = 0;
    Q.push(source);
    //cout << source << endl;
    while(!Q.empty())
    {
        pair<int,int> u;
        u = Q.front();
        Q.pop();
        //cout << u << endl;
            //cout << v << endl;
        for(int i=0; i<4; i++)
            {
            if(i == 0){a = u.first + 1;
            b = u.second;}
            else if(i==1)
            {
                a = u.first;
                b = u.second + 1;
            }
            else if(i==2)
            {
                a = u.first-1;
                b = u.second;
            }
            else
            {
                a = u.first;
                b = u.second - 1;
            }
            pair<int,int> v;
            v = make_pair(a,b);
            if ((a < R) && (b < C) && (a >= 0) && (b >= 0) &&  (vis[v.first][v.second] == false))
            {
                cost[v.first][v.second] = cost[u.first][u.second] + 1;
                vis[v.first][v.second] = true;
                if(v == destination) return cost[v.first][v.second];
                Q.push(v);
            }
        }

        //cout << endl;
    }
}

int main()
{

    int P, row, col, bombs;
    while(cin >> R >> C)
    {
        if(R == 0 && C ==0) break;
    cin >> P;
    reset();
    for(int i=0; i<P; i++)
    {
        cin >> row >> bombs;
        for(int j=0; j<bombs; j++)
        {
            cin >> col;
            pair <int, int> P;
            P = make_pair(row, col);
            vis[row][col] = 1;
        }
    }
    int x,y;
    cin >> x >> y;
    source = make_pair(x,y);
    cin >> x >> y;
    destination = make_pair(x,y);
    cout << bfs() << endl;
    }
}
