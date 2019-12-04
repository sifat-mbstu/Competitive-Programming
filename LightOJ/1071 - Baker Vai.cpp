#include<bits/stdc++.h>
using namespace std;
#define   ff   first
#define   ss   second
#define   pb   push_back
#define   mp   make_pair

#define   SQ(n)         (n*n)
#define   ll            long long
#define   llu           unsigned long long

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
int n,m;
int grid[105][105];
int dp[103][103][103][3];
int fun(int row, int c1, int c2, int nxt)
{
    if(row==n-1 && c1 == m-2 && c2==m-1 && nxt==0)
    {
        return 0;
    }
    int &ret = dp[row][c1][c2][nxt];
    if(ret!=-1)return ret;
    int ret1 = 0, ret2 = 0, ret3 = 0;

    if(nxt==2)
    {
        if(row+1<n) ret1 = fun(row+1,c1,c2,0) + grid[row+1][c1] + grid[row+1][c2];
    }
    if(nxt==1)
    {
        if(c2+1<m && c2>c1) ret2 = fun(row,c1,c2+1,1) + grid[row][c2+1];
        ret2 = max( ret2, fun(row,c1,c2,2) );
    }
    if(nxt==0)
    {
        if(c1+1<c2 && c1+1<m) ret3 = fun(row,c1+1,c2,0) + grid[row][c1+1];
        ret3 = max(ret3, fun(row,c1,c2,1) );
    }
    return ret = max(ret1, max(ret2, ret3));
}
int main()
{
    int tc,idx=0;
    sf(tc);
    while(tc--){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    MEM(dp,-1);
    int res = fun(0,0,1,1)+grid[0][0]+grid[0][1] ;
    pfc(++idx);
    pf(res);pnl();
    }
}
