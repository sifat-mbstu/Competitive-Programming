//#define BitCnt(a) __builtin_popcountll(a)
//#define MEM(a,val) memset(a,val,sizeof(a))

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

#define pi 2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
#define mx 100010
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
vi G[mx];
int lev[mx];
int path[mx];
int par[mx];
void bfs(int src)
{
    lev[src] = 1;
    queue <int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        sort(G[u].begin(), G[u].end());
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if(lev[v]==inf)
            {
                lev[v] = lev[u] + 1;
                par[v] = u;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int TC, ind = 0;
    sf(TC);
    while(TC--){
    int n, pre, val, src,des;
    sf(n);
    for(int i=0; i<mx; i++)
    {
        G[i].clear();
        lev[i] = inf;
        par[i] = -1;
    }
    sf(pre);
    src = pre;
    for(int i=1; i<n; i++)
    {
        sf(val);
        G[pre].pb(val);
        G[val].pb(pre);
        pre = val;
    }
    des = val;
    bfs(src);
    int idx = 0;
    int cur = des;
    path[idx++] = cur;
    while(par[cur]!=-1)
    {
        cur = par[cur];
        path[idx++] = cur;
    }
    printf("Case %d:\n",++ind);
    printf("%d", path[idx-1]);
    for(int i = idx-2; i>=0; i--)
    {
        printf(" %d", path[i]);
    }
    printf("\n");
    }
}
