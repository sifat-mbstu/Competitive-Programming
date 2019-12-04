
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
int seq[1010100];
int fre[1011];
int main()
{
    int TC,ind = 0;
    cin >> TC;
    while(TC--){
    int n,m,k;
    scanf("%d %d %d",&n, &m, &k);
    memset(seq,0,sizeof(seq));
    memset(fre,0,sizeof(fre));
    seq[1] = 1;
    seq[2] = 2;
    seq[3] = 3;
    seq[4] = 6%m + 1;
    int cur = 6;
    for(int i=4; i<n; i++)
    {
        cur += seq[i];
        cur -= seq[i-3];
        seq[i+1] = cur%m+1;
    }
    int cnt = 0;
    int j=1;
    int Min = inf;
    for(int i=1; i<=n; i++)
    {
        int val = seq[i];
        if(val<=k)
        {
            if(!fre[val])
            {
                cnt++;
            }
            fre[val]++;
            if(cnt==k)
            {
                while(cnt==k)
                {
                    Min = min(Min, i-j+1);
                    int now = seq[j++];
                    if(now<=k)
                    {
                        fre[now]--;
                        if(!fre[now])
                        {
                            cnt--;
                        }
                    }
                }
            }

        }
    }
    if(Min == inf)
    {
        printf("Case %d: sequence nai\n",++ind);
    }
    else{printf("Case %d: %d\n",++ind,Min);}
    }
}
