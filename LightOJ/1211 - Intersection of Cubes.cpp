#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vd vector<double>
vd now[200];
bool if_inside(int t1, double x, double y, double z)
{
    if((x>= now[t1][0] && x<=now[t1][3]) && (y>= now[t1][1] && y<=now[t1][4]) && (z>= now[t1][2] && z<=now[t1][5]))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        double x1,x2,y1,y2,z1,z2;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2);

        now[i].pb(x1); now[i].pb(y1); now[i].pb(z1);
        now[i].pb(x2); now[i].pb(y2); now[i].pb(z2);
    }
    bool vis[200];
    memset(vis,0,sizeof(vis));
    int cnt = 200;
    int prev;
    while(cnt!=1){
            prev = cnt;
            cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(vis[i]) continue;
        cnt++;
        for(int j=0; j<n; j++)
        {
            if(vis[j]) continue;
            if(i==j)continue;
            if (if_inside(i, now[j][0],now[j][1],now[j][2]))
            {
                cout << "hh1" << endl;
                if (if_inside(i, now[j][3],now[j][4],now[j][5]))
                {
                cout << "===>hh1" << endl;
                    now[i] = now[j];
                    vis[j] = 1;
                }
                else if (if_inside(j, now[i][3],now[i][4],now[i][5]))
                {
                cout << "===>hh1" << endl;
                    vd cur;
                    cur.pb(now[j][0]); cur.pb(now[j][1]); cur.pb(now[j][2]);
                    cur.pb(now[i][3]); cur.pb(now[i][4]); cur.pb(now[i][5]);
                    now[i] = cur;
                    vis[j] = 1;
                }
            }
            else if (if_inside(j, now[i][0],now[i][1],now[i][2]))
            {
                cout << "hh2" << endl;
                if (if_inside(j, now[i][3],now[i][4],now[i][5]))
                {
                cout << "===>hh2" << endl;
                    now[j] = now[i];
                    vis[i] = 1;
                }
                else if (if_inside(i, now[j][3],now[j][4],now[j][5]))
                {
                cout << "===>hh2" << endl;
                    vd cur;
                    cur.pb(now[i][0]); cur.pb(now[i][1]); cur.pb(now[i][2]);
                    cur.pb(now[j][3]); cur.pb(now[j][4]); cur.pb(now[j][5]);
                    now[j] = cur;
                    vis[i] = 1;
                }
            }
        }
    }
    if(prev<=cnt)break;
    }
    for(int i=0; i<n; i++)
    {
        if(vis[i]) continue;
        for(int j=0; j<now[i].size(); j++)
        {
            cout << now[i][j] << "=";
        }
        cout << endl;
    }
}
