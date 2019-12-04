///   |----------------------------|
///   | BISMILLAHIR RAHMANIR RAHIM |
///   |----------------------------|

///       _______  __   ________   ___   .___________.
///      /       ||  | |   ____|  /   \  |           |
///     |   (----'|  | |  |__    /  ^  \ `---|  |----`
///      \   \    |  | |   __|  /  /_\  \    |  |
///  |----)   |   |  | |  |    /  _____  \   |  |
///  |_______/    |__| |__|   /__/     \__\  |__|
///


//#define BitCnt(a) __builtin_popcountll(a)

//template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
//template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
//template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
//template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
//long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
//bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
//template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
//long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
//bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//#define good   st<=l&&ed>=r
//#define seg    int mid=(l+r)/2,lft=2*id,rgt=lft+1
//#define MX  500007
///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll long long
#define llu unsigned long long

#define pi acos(-1.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define MEM(a,val) memset(a,val,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define tover(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define nover(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
#define mx 200010
int vis[mx], low[mx],dis[mx],isBridge[mx],tym,cnt_cmp;
int used[mx];
bool mat[101][101];
struct st
{
    int v,num;
};
vector<st>G[mx];
vector<int>tree[mx];
void find_bridge(int u, int p)
{
    vis[u] = 1;
    dis[u] = low[u] = tym++;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i].v;
        int num = G[u][i].num;
        if(v==p)
            continue;
        if(!vis[v])
        {
            find_bridge(v,u);
            if(dis[u]<low[v] && !(mat[u][v] && mat[v][u]))
            {
                isBridge[num] = 1;
            }
            low[u] = min(low[u],low[v]);
        }
        else
        {
            low[u] = min(low[u],dis[v]);
        }
    }
}

void bridge_tree(int src)
{
    used[src] = 1;
//    comp_no[src] = cnt_cmp;
    int cur_cmp = cnt_cmp;
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i].v;
            int num = G[u][i].num;
            if(used[v])
                continue;
            if(isBridge[num])
            {
                cnt_cmp++;
                tree[cur_cmp].pb(cur_cmp+1);
//                tree[cur_cmp+1].pb(cur_cmp);
                bridge_tree(v);
            }
            else
            {
                Q.push(v);
                used[v] = 1;
//                comp_no[v] = cur_cmp;
            }
        }
    }
}

void chkDFS(int src)
{
    vis[src] = 1;
//    cout <<"tttt " << src << endl;
    for(int i=0; i<min((int)tree[src].size(),1); i++)
    {
        int v = tree[src][i];
        if(!vis[v])
            chkDFS(v);
    }
}
void reset()
{
    cnt_cmp = 0;
    tym = 0;
    memset(low,0,sizeof(low));
    memset(dis,0,sizeof(dis));
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(isBridge,0,sizeof(isBridge));
    for(int i=0; i<=1000; i++)
    {
        tree[i].clear();
        G[i].clear();
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int TC,idx = 0;
    sf(TC);
    while(TC--)
    {

        int n,m;
        sf(n);
        set<int> nodes;
        set<int> :: iterator it;
        reset();
        int ii = 1;
        while(n--)
        {
            sf(m);
            while(m--)
            {
                int u,v;
                sf2(u,v);
//            cout << u << " " << v << endl;
                G[u].pb({v,ii});
                mat[u][v] = 1;
                nodes.insert(u);
                nodes.insert(v);
                ii++;
            }
//        G[v].pb({u,i});
//        root = min(root,min(u,v));
        }
        find_bridge(0,-1);
        bool res = 1;
        for(it = nodes.begin(); it!=nodes.end(); it++)
        {
            int val = *it;
            if(!vis[val])
                res = 0;
        }
        if(res==0)
        {
            printf("Case %d: NO\n",++idx);
            ///Print No
            continue;
        }

//    for(int i=1; i<=1000; i++)
//        if(isBridge[i])
//            cout <<"B=>" << i << endl;

        bridge_tree(0);

        for(int i=0; i<=10; i++)
        {
            cout << i << " : ";
            if(tree[i].size())
            {
                for(int j=0; j<tree[i].size(); j++)
                {
                    cout << tree[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << "=>" << cnt_cmp << endl;

        memset(vis,0,sizeof(vis));
        chkDFS(0);
        for(int i=0; i<=cnt_cmp; i++)
        {
            if(!vis[i])
                res = 0;
        }
        if(res)
            printf("Case %d: YES\n",++idx);
        else
            printf("Case %d: NO\n",++idx);
    }
}
