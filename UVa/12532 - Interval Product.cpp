//#define BitCnt(a) __builtin_popcountll(a)

//template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
//template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
//template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
//template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
//long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
//bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
//template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
//long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
//bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//#define good   st<=l&&ed>=r
//#define seg    int mid=(l+r)/2,lft=2*id,rgt=lft+1
//#define MX  500007
///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll long long
#define llu unsigned long long

#define pi acos(-1.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define MEM(a,val) memset(a,val,sizeof(a))

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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
#define mx 100010
int arr[100010];
int tree[4*mx];

void build(int b, int e, int node)
{
    if(b==e)
    {
        tree[node] = arr[b];
//            printf("tree[%d] = %d --- arr[%d] = %d\n",node,tree[node],b,arr[b]);
        return;
    }
    int mid = (b+e)/2;
    build(b,mid,node*2);
    build(mid+1,e,node*2+1);
    tree[node] = tree[node*2] * tree[node*2+1];
}
void update(int b, int e, int qb, int qe, int node, int val)
{
    if(no_overlap(qb,qe,b,e)) return;
    if(total_overlap(qb,qe,b,e))
    {
        tree[node] = val;
        return;
    }
    int mid = (b+e)/2;
    update(b,mid,qb,qe,node*2,val);
    update(mid+1,e,qb,qe,node*2+1,val);
    tree[node] = tree[node*2]*tree[node*2+1];
}
int query(int b, int e, int qb, int qe, int node)
{
    if(no_overlap(qb,qe,b,e)) return 1;
    if(total_overlap(qb,qe,b,e)) {return tree[node];}
    int mid = (b+e)/2;
    int aa = query(b,mid,qb,qe,node*2);
    int bb = query(mid+1,e,qb,qe,node*2+1);
    return aa*bb;
}
void reset()
{
    memset(tree,0,sizeof(tree));
    memset(arr,0,sizeof(arr));
}
int main()
{
    int n,q;
    while(sf2(n,q)==2){
        reset();
    for(int i=0; i<n; i++)
    {
        sf(arr[i]);
        if(arr[i]>0) arr[i] = 1;
        else if(arr[i]<0) arr[i] = -1;
        else arr[i] = 0;
    }
    build(0,n-1,1);
    string ans="";
    while(q--)
    {
        char ss[10];
        int p1, p2;
        scanf("%s %d %d",ss,&p1,&p2);
        if(ss[0]=='P')
        {
            int st = min(p1,p2)-1;
            int en = max(p1,p2)-1;
            int res = query(0,n-1,st,en,1);
            if(res==1) ans+='+';
            else if(res==-1) ans+='-';
            else ans += '0';
        }
        else if(ss[0]=='C')
        {
            int val = p2;
            int idx = p1-1;
            if(val>0) val = 1;
            else if(val<0) val = -1;
            else val = 0;
            update(0,n-1,idx,idx,1,val);
//        for(int i=1; i<=13; i++)
//        {
//            printf("tree[%d] = %d\n",i,tree[i]);
//        }
        }
    }
    cout << ans << endl;
    }
}
