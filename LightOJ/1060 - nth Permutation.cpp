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

#define   pfc(a)         printf("Case %d: ",a)
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
string s;
string str;
string res;
int fre[30];
int koi;
int n;
ll fac[25];
ll per() {
    ll lob = 1;
    ll hor = 1;
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += fre[i];
        hor *= fac[fre[i]];
    }
    ll res = fac[sum] / hor;
    return res;
}
bool flag = 0;
void fun(int pos) {
    if (pos == n) {
        flag = 1;
        res = str;
//        cout << str << endl;
        return;
    }
    ll sum = 0 ;
    ll pre = 0;
    for (int i = 0; i < 26; i++) {
        if (fre[i] > 0) {
            fre[i]--;
            ll now = per();
            pre = sum;
            sum += now;
            if (sum >= koi) {
                koi -= pre;
                str += 'a' + i;
                fun(pos + 1);
                str.pop_back();
                break;
            }
            fre[i]++;
        }
    }
}
int main() {
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fac[i] = fac[i - 1] * i;
    }
    int tc,idx=0;
    sf(tc);
    while(tc--){
        flag = 0;
    cin >> s >> koi;
    MEM(fre,0);
    n = s.size();
    for (int i = 0; i < n; i++) {
        int v = s[i] - 'a';
        fre[v]++;
    }
    fun(0);
    if(!flag) {pfc(++idx);cout << "Impossible" << endl;}
    else
    {
        pfc(++idx);cout << res<< endl;
    }
}
}
