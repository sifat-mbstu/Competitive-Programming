///Accepted (Time: 0.320s)
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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define MX  100001
#define inf INT_MAX/3
#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW
int in[MX];
int tree[MX*3];

void build(int lo, int hi, int pos)
{
    if(lo==hi){tree[pos] = in[lo]; return;}
    int mid = (lo+hi)/2;
    build(lo,mid,2*pos+1);
    build(mid+1,hi, 2*pos+2);
    tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
}
int rmq(int qlo, int qhi, int lo, int hi, int pos)
{
    if(total_overlap(qlo, qhi, lo, hi))
    {
        return tree[pos];
    }
    if(no_overlap(qlo, qhi, lo, hi))
    {
        return inf;
    }
    int mid = (lo+hi)/2;
    return min(rmq(qlo, qhi, lo, mid,pos*2+1), rmq(qlo, qhi,mid+1 ,hi, pos*2+2)) ;
}
int main()
{
    int TC, ind=0;
    scanf("%d",&TC);
    while(TC--){
    int n,q;
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&in[i]);
    }
    build(0,n-1,0); /// (lo,hi,pos)____ it is 0 based ____
    printf("Case %d:\n",++ind);
    for(int i=0; i<q; i++)
    {
        int a, b;
        scanf("%d %d",&a, &b);
        printf("%d\n",rmq(a-1,b-1,0,n-1,0));
    }
    }
}

