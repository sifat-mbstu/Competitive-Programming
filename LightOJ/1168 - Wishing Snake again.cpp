///ACCEPTED
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
#define mx 1010

vi G[mx], R[mx], Dir[mx];
vi Ans[mx];
bool yes;
int col[mx];
bool vis[mx];
bool vis2[mx];

stack <int> st;
void dfs1(int u)
{
    vis[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!vis[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, int ii)
{
    vis2[u] = 1;
    for(int i=0; i<R[u].size(); i++)
    {
        int v = R[u][i];
        if(!vis2[v])
        {
            dfs2(v,ii);
        }
    }
    Ans[ii].pb(u);
}
void chkDFS(int src)
{
    vis[src] = 1;
    if(Dir[src].size()>=2)
        yes = 0;
    for(int i=0; i<Dir[src].size(); i++)
    {
        int v = Dir[src][i];
        if(!vis[v])
            chkDFS( v );
    }
}

void reset()
{
    yes = 1;
    for(int i=0; i<mx; i++)
    {
        Ans[i].clear();
        G[i].clear();
        R[i].clear();
        Dir[i].clear();
        vis[i] = vis2[i] = col[i] = 0;
    }
    while(!st.empty()) st.pop();
}

int main()
{
    int TC,idx=0;
    sf(TC);
    while(TC--)
    {
        reset();
        int m = 0;
        int n1,n2;
        set<int>Set;
        set<int> :: iterator it;
        sf(n1);
        while(n1--)
        {
            sf(n2);
            while(n2--)
            {
                int u,v;
                sf2(u,v);
                G[u].pb(v);
                R[v].pb(u);
                Set.insert(u);
                Set.insert(v);
                m++;
            }
        }
        yes = 1;
        dfs1(0);
        for(it = Set.begin(); it!=Set.end(); it++)
        {
            int u = *it;
            if(!vis[u])
                yes = 0;
        }
        if(!yes)
        {
            printf("Case %d: NO\n",++idx);
            continue;
        }

        int ii = 0;
        while(!st.empty())
        {
            int a = st.top();
            st.pop();
            if(!vis2[a])
            {
                dfs2(a, ++ii);
            }
        }
        for(int i=1; i<=ii; i++)
        {
            for(int j=0; j<Ans[i].size(); j++)
            {
                col[Ans[i][j]] = i;
            }
        }
        for( it=Set.begin(); it!=Set.end(); it++)
        {
            int bb = *it;
            for(int j=0; j<G[bb].size(); j++)
            {
                int v = G[bb][j];
                if(col[bb] != col[v])
                {
                    Dir[col[bb]].pb(col[v]);
                }
            }
        }
        memset(vis,0,sizeof(vis));
        chkDFS(1);
        for(int i=1; i<=ii; i++)
        {
            if(!vis[i])
                yes = 0;
        }
        if(yes)
            printf("Case %d: YES\n",++idx);
        else
            printf("Case %d: NO\n",++idx);
    }
}
