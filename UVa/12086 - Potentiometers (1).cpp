///Done
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
#define MX  200010
#define inf INT_MAX/3
#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW
int in[MX];
int tree[MX*4];

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
void update_a_single(int lo, int hi, int pos, int loc, int val)
{
    if(no_overlap(loc, loc, lo, hi))
        return;

    if(total_overlap(loc, loc, lo, hi))
    {
        tree[pos] = val;
        return;
    }
    int mid  = (lo+hi)/2;
    update_a_single(lo,mid, pos*2+1, loc, val);
    update_a_single(mid+1,hi, pos*2+2, loc, val);
    tree[pos] = tree[pos*2+1] + tree[pos*2+2];
}
int main()
{
    int n,q,ind = 0;
    while(scanf("%d",&n)==1){
    if(!n) break;
    if(ind!=0) printf("\n");
    memset(in,0,sizeof(in));
    memset(tree,0,sizeof(tree));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&in[i]);
    }
    build(0,n-1,0);
    getchar();
    string str;
    printf("Case %d:\n",++ind);
    while(getline(cin,str))
    {
        if(str=="END") break;
        int choise;
        if(str[0]=='S') choise = 1;
        else choise = 2;
        int y=0,x=0,z,mul = 1;
        for(z=str.size()-1; z>=0; z--)
        {
            if(str[z]==' ') break;
            x += (str[z] - '0')*mul;
            mul *= 10;
        }
        mul = 1;
        z--;
        for( ; z>=0; z--)
        {
            if(str[z]==' ') break;
            y += (str[z] - '0')*mul;
            mul *= 10;
        }
        if(choise==1)
        {
            int val, loc;
            loc = y;
            val = x;
            loc--;
//            printf("loc = %d val = %d\n",loc,val);
            update_a_single(0,n-1,0,loc, val);
        }
        else if(choise == 2)
        {
            int a, b;
            a = x, b = y;
            a--;
            b--;
            if(a>b) swap(a,b);
//            printf("a = %d b = %d\n",a,b);
            printf("%d\n",rmq(a,b,0,n-1,0));
        }
    }
    }
}

