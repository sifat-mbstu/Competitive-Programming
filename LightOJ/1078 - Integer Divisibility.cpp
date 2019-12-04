
///Accepted
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll int
#define llu unsigned long long

#define pi 2.0*acos(0.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(ll i=a;i<b; i++)

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
int is_divisible(int n, int k)
{
    if(k<0) k *= -1;
    int sum = 0;
    int cnt = 0;
    int i;
    for( i=0; ; i++)
    {
        cnt++;
        sum = sum*10 + n;
//        printf("sum = %d k = %d i = %d\n",sum,k, i);
//        getchar();
        if(sum < k)
        {
            continue;
        }
        else if(sum % k == 0)
        {
            sum = 0;
//            cout << " i = " << i << endl;
            return i;
        }
        else
        {
            int multi = floor((double)sum/(double)k);
            sum = sum - k*multi;
        }
    }
}
int main()
{
//    FO;
    ll TC, ind = 0;
    sf(TC);
    while(TC--)
    {
        int nn,k;
        sf2(nn,k);
//        cout << "nn = " << nn << endl;
//        string s= "";
//        cout << is_divisible(k,nn) << endl;
        printf("Case %d: %d\n",++ind,is_divisible(k,nn)+1);
    }
}
