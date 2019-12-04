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
string binary(int num)
{
    string s;
    while(num!=0)
    {
        int a = num%2;
        s += (a+'0');
        num /= 2;
    }
    reverse(s.begin(), s.end());
    while(s.size()!=8)
    {
        s.insert(s.begin(),'0');
    }
    return s;
}
int main()
{
    int ind = 0, TC;
    cin >> TC;
    while(TC--){
    int a1,a2,a3,a4;
    string s1,s2,s3,s4;
    string SS[10];
    scanf("%d.%d.%d.%d",&a1,&a2,&a3,&a4);
    s1 = binary(a1);
    s2 = binary(a2);
    s3 = binary(a3);
    s4 = binary(a4);

    string s, str;
    cin >> s;
    int index = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(i==s.size()-1){str += s[i];}
        if(s[i]=='.' || (i==s.size()-1)){
            SS[index++] = str;
            str = "";
        }
        else str += s[i];
    }
//    cout << s1 << endl << s2 << endl  << s3 << endl  << s4 << endl ;
//    cout << SS[0] << endl << SS[1] << endl  << SS[2] << endl  << SS[3] << endl ;

    if(SS[0]==s1 && SS[1]==s2 && SS[2]==s3 && SS[3]==s4)
    {
        printf("Case %d: Yes\n",++ind);
    }
    else
    {
        printf("Case %d: No\n",++ind);
    }
    }
}
