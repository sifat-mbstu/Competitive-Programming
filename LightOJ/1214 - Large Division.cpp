///Accepted
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

#define FOR(i,a,b) for(ll i=a;i<b; i++)

#define sf(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3

int main()
{
    ll TC, ind = 0;
    sf(TC);
    while(TC--)
    {
        string n;
        ll k;
        cin >> n;
        sf(k);
        if(n[0] == '-')
        {
            n.erase(n.begin());
        }
        if(k<0) k *= -1;
        if(k==0) {printf("Case %lld: not divisible\n",++ind); continue;}
        ll sum = 0;
        for(ll i=0; i<n.size(); i++)
        {
            sum = sum*10 + (n[i]-'0');
            if(sum < k) { continue;}
            else if(sum == k){sum = 0;}
            else
            {
                ll multi = floor((double)sum/(double)k);
                sum = sum - k*multi;
            }
        }
        if(sum==0) printf("Case %lld: divisible\n",++ind);
        else {printf("Case %lld: not divisible\n",++ind);}
    }
}
