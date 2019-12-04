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
///**********************************************************//
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

#define   pfl(a)        printf("%lld",a)
#define   pfl2(a,b)     printf("%lld %lld",a,b)
#define   pfl3(a,b,c)   printf("%lld %lld %lld",a,b,c)
#define   pfl4(a,b,c,d) printf("%lld %lld %lld %lld",a,b,c,d)

#define   tover(QLOW, QHIGH, LOW, HIGH)   QLOW<=LOW && QHIGH>= HIGH
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
#define   vll       vector<ll>
#define   FI       freopen("in.txt", "r", stdin)
#define   FO       freopen("out.txt", "w", stdout)
#define   MOD      1000000007
#define   inf      11111111111111

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

#define   fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
double dp[502][502][2];
double fun(int R, int B, int state)
{
    if(R==0) return 1.0;
    if(B==0) return 0.0;
    double &ret = dp[R][B][state];
    if(ret>=0.0) return ret;
    double n1=0.0,n2=0.0;
    if(!state)
    {
        n1 = ((double)R/((double)R+(double)B)) * fun(R-1,B,!state);
        n2 = ((double)B/((double)R+(double)B)) * fun(R,B-1,!state);
    }
    else
    {
        n1 = fun(R,B-1,!state);
    }
    return  ret = n1+n2;
}
int main()
{
    int tc,idx=0;
    sf(tc);
    MEM(dp,-1.0);
    while(tc--){
    int R,B;
    sf2(R,B);
    double res = fun(R,B,0);
    pfc(++idx);
    printf("%.10lf\n",res);
    }
}
