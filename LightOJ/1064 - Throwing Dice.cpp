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
//long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
//template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
//bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//#define good   st<=l&&ed>=r
//#define seg    int mid=(l+r)/2,lft=2*id,rgt=lft+1
//#define MX  500007
///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define   ff   first
#define   ss   second
#define   pb   push_back
#define   mp   make_pair

#define   SQ(n)         (n*n)
#define   ll            long long
//#define   ll           unsigned long long

#define   pi            acos(-1.0)

#define   all(a)        a.begin(),a.end()
#define   _max(a,b,c)   Max(a,Max(b,c))
#define   _min(a,b,c)   Min(a,Min(b,c))

#define   FOR(i,a,b)    for(int i=a;i<b; i++)

#define   MEM(a,val)    memset(a,val,sizeof(a))

#define   sf(a)         scanf("%d",&a)
#define   sf2(a,b)      scanf("%d%d",&a,&b)
#define   sf3(a,b,c)    scanf("%d%d%d",&a,&b,&c)
#define   sf4(a,b,c,d)  scanf("%d%d%d%d",&a,&b,&c,&d)

#define   sfl(a)        scanf("%lld",&a)
#define   sfl2(a,b)     scanf("%lld%lld",&a,&b)
#define   sfl3(a,b,c)   scanf("%lld%lld%lld",&a,&b,&c)
#define   sfl4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define   pnl()         printf("\n")

#define   pfc(a)        printf("Case %d: ",a)
#define   pf(a)         printf("%d",a)
#define   pf2(a,b)      printf("%d %d",a,b)
#define   pf3(a,b,c)    printf("%d %d %d",a,b,c)
#define   pf4(a,b,c,d)  printf("%d %d %d %d",a,b,c,d)

#define   pflc(a)       printf("Case %lld: ",a)
#define   pfl(a)        printf("%lld",a)
#define   pfl2(a,b)     printf("%lld %lld",a,b)
#define   pfl3(a,b,c)   printf("%lld %lld %lld",a,b,c)
#define   pfl4(a,b,c,d) printf("%lld %lld %lld %lld",a,b,c,d)

#define   tover(QLOW, QHIGH, LOW, HIGH)   QLOW<=LOW && QHIGH>= HIGH /// QLOW,QHIGH = Jei Query Ber korbo
#define   nover(QLOW, QHIGH, LOW, HIGH)   QLOW>HIGH || QHIGH<LOW

#define   bitCheck(a,k)  ((bool)(a&(1<<(k))))
#define   bitOff(a,k)    (a&(~(1<<(k))))
#define   bitOn(a,k)     (a|(1<<(k)))
#define   bitFlip(a,k)   (a^(1<<(k)))

#define   POPCOUNT       __builtin_popcount
#define   POPCOUNTLL     __builtin_popcount
#define   RIGHTMOST      __builtin_ctzll
#define   LEFTMOST(x)    (63-__builtin_clzll((x)))

#define   pii      pair<int,int>
#define   pll      pair<ll,ll>
#define   vi       vector<int>
#define   FI       freopen("in.txt", "r", stdin)
#define   FO       freopen("out.txt", "w", stdout)
#define   MOD      1000000007
#define   inf      INT_MAX/3

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

#define   fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
        ll n,x;
        ll dp[26][150];
ll fun(ll pos, ll rest)
{
    if(pos==n)return 1;
    ll &sum = dp[pos][rest];
    if(sum!=-1)return sum;
     sum = 0;
    for(int i=1; i<=6; i++)
    {
        if(rest-i<0) break;
        sum += fun(pos+1,rest-i);
    }
    return sum;
}
pll process(ll lob, ll hor)
{
    ll gcd = __gcd(lob,hor);
    lob = lob/gcd;
    hor = hor/gcd;
    return pll(lob,hor);
}
int main()
{
    ll p6[30];
    p6[0] = 1;
    for(int i=1; i<25; i++)
    {
        p6[i] = p6[i-1]*6LL;
    }
    ll tc,idx=0;
    cin >> tc;
    while(tc--)
    {
        MEM(dp,-1);
        cin >> n >> x;
        ll res,lob,hor;
        if(x<=n){
            lob = 1;
            hor = 1;
        }
        else
        {
            ll now = fun(0,x-1);
            lob = p6[n] - now;
            hor = p6[n];
        }
        pll fin = process(lob,hor);
        lob = fin.first;
        hor = fin.second;
        if(lob==0 || hor==1)printf("Case %lld: %lld\n",++idx,lob);
        else printf("Case %lld: %lld/%lld\n",++idx,lob,hor);
    }
}
