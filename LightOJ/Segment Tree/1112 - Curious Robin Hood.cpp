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
int choise;

void build(int lo, int hi, int pos)
{
    if(lo==hi)
    {
        tree[pos] = in[lo];
        return;
    }
    int mid = (lo+hi)/2;
    build(lo,mid,2*pos+1);
    build(mid+1,hi, 2*pos+2);
    tree[pos] = tree[pos*2+1] + tree[pos*2+2];
}

int rmq(int qlo, int qhi, int lo, int hi, int pos)
{
    if(total_overlap(qlo, qhi, lo, hi))
    {
        return tree[pos];
    }
    if(no_overlap(qlo, qhi, lo, hi))
    {
        return 0;
    }
    int mid = (lo+hi)/2;
    return rmq(qlo, qhi, lo, mid,pos*2+1) + rmq(qlo, qhi,mid+1,hi, pos*2+2) ;
}
int loc,val;
void update_a_single(int lo, int hi, int pos)
{
    if(no_overlap(loc, loc, lo, hi))
        return;

    if(total_overlap(loc, loc, lo, hi))
    {
        if(choise == 1) tree[pos] = 0;
        else tree[pos] += val;

        return;
    }
    int mid  = (lo+hi)/2;
    update_a_single(lo,mid, pos*2+1);
    update_a_single(mid+1,hi, pos*2+2);
    tree[pos] = tree[pos*2+1] + tree[pos*2+2];
}

int main()
{
    int tc,ind=0;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&in[i]);
        }
        build(0,n-1,0);
        printf("Case %d:\n",++ind);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&choise);
            if(choise==1)
            {
                scanf("%d",&loc);
                printf("%d\n",in[loc]);
                in[loc] = 0;
                update_a_single(0,n-1,0);
            }
            else if(choise==2)
            {
                scanf("%d %d",&loc,&val);
                in[loc] += val;
                update_a_single(0,n-1,0);
            }
            else if(choise == 3)
            {
                int a, b;
                scanf("%d %d",&a, &b);
                printf("%d\n",rmq(a,b,0,n-1,0));
            }
        }
    }
}
