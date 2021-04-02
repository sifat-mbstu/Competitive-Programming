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
//---Code Start Here
#define mx 60005
int N;
int tree[mx*4],en[mx], par[mx],arr[mx], in[mx], L[mx], cst[mx],P[mx][20];
vi G[mx];
int tym;
void dfs(int u, int fr)
{
    par[u] = fr;
    L[u] = L[fr]+1;
    in[u] = ++tym;
    cst[tym] = arr[u];
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(v==par[u])
            continue;
        dfs(v,u);
    }
    en[u] =++tym;
    cst[tym] = -arr[u];
}
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = cst[b];
        return;
    }
    int mid = (b+e)/2;
    int L = 2*node;
    int R = L+1;
    build(L,b,mid);
    build(R,mid+1,e);
    tree[node] = tree[L]+tree[R];
}
void lca_init(int n)
{
    memset(P,-1,sizeof(P));
    for(int i=0; i<n; i++)
    {
        P[i][0] = par[i];
    }
    for(int j=1; (1<<j) < n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
void update(int node,int b,int e,int pos,int val)
{
    if(b==e)
    {
        tree[node]=val;
        return;
    }
    int mid=(b+e)/2;
    int L = 2*node;
    int R = L+1;
    if(pos<=mid)
        update(L,b,mid,pos,val);
    else
        update(R,mid+1,e,pos,val);

    tree[node]=tree[L]+tree[R];
}

int query(int node,int b,int e,int i,int j)
{
    if(nover(i,j,b,e))
        return 0;
    if(tover(i,j,b,e))
        return tree[node];

    int mid=(b+e)/2;
    int L=node*2;
    int R = L+1;

    int ret1 = query(L,b,mid,i,j);
    int ret2 = query(R,mid+1,e,i,j);
    return ret1+ret2;
}
int lca_query(int N, int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])
            break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return par[p];
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int TC, idx = 0;
    sf(TC);
    while(TC--)
    {
        sf(N);
        for(int i=0; i<=N; i++)
            G[i].clear();
        for(int i=0; i<N; i++)
            sf(arr[i]);
        FOR(i,1,N)
        {
            int u,v;
            sf2(u,v);
            G[u].pb(v);
            G[v].pb(u);
        }
        tym = 0;
        dfs(0,-1);
        build(1,1,2*N);
        lca_init(N);

        int q;
        sf(q);
        printf("Case %d:\n",++idx);
        while(q--)
        {
            int chose, x, y;
            sf3(chose,x,y);
            if(chose)
            {
                update(1,1,2*N,in[x],y);
                update(1,1,2*N,en[x],-y);
                arr[x] = y;
            }
            else
            {
                int lca = lca_query(N,x,y);
                int v1 = query(1,1,2*N,in[lca],in[x]);
                int v2 = query(1,1,2*N,in[lca],in[y]);
                int res = v1+v2-arr[lca];
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
