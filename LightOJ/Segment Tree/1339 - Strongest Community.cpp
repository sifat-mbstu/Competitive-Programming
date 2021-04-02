
///       _______. __   _______    ___   .___________.
///      /       ||  | |   ____|  /   \  |           |
///     |   (----`|  | |  |__    /  ^  \ `---|  |----`
///      \   \    |  | |   __|  /  /_\  \    |  |
///  .----)   |   |  | |  |    /  _____  \   |  |
///  |_______/    |__| |__|   /__/     \__\  |__|
///


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

#define tover(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define nover(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
#define mx  500007
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define pii pair<int,int>
struct st
{
    int L,R,lenL,lenR,mxlen;
}tree[mx*4];

int arr[mx];
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].L = arr[b];
        tree[node].R = arr[b];
        tree[node].lenL = 1;
        tree[node].lenR = 1;
        tree[node].mxlen = 1;
        return;
    }
    int LL = node*2;
    int RR = LL+1;
    int mid = (b+e)/2;

    build(LL, b, mid);
    build(RR, mid+1, e);

    int left = abs(mid-b)+1;
    int r8 = abs(e-mid);
//    cout << "b = " << b << " e = " << e << endl;
//    cout << left << " = left r8 = " << r8 << endl;
    /// find left side
    if(tree[LL].lenL==left && tree[LL].L == tree[RR].L)
    {
            tree[node].lenL = tree[LL].lenL + tree[RR].lenL;
    }
    else tree[node].lenL = tree[LL].lenL;

    tree[node].L = tree[LL].L;

    /// Find right side
    if(tree[RR].lenR==r8 && tree[RR].R == tree[LL].R)
    {
            tree[node].lenR = tree[RR].lenR+tree[LL].lenR;
    }
    else tree[node].lenR = tree[RR].lenR;
    tree[node].R = tree[RR].R;

///** Finda mx len
    int MAX =max(tree[node].lenL, tree[node].lenR);
    MAX = max(MAX, tree[LL].mxlen);
    MAX = max(MAX, tree[RR].mxlen);
    if(tree[LL].R == tree[RR].L)
    {
        MAX = max(MAX, tree[LL].lenR+tree[RR].lenL);
    }
    tree[node].mxlen = MAX;
}
st query(int node, int b, int e, int i, int j)
{
    if(nover(i,j,b,e))
    {
        st ret;
        ret.lenL = -inf;
        ret.lenR = -inf;
        ret.mxlen = -inf;
        return ret;
    }
    if(tover(i,j,b,e))
    {
        return tree[node];
    }


    int LL = node*2;
    int RR = LL+1;
    int mid = (b+e)/2;

    st retL = query(LL, b, mid,i,j);
    st retR = query(RR, mid+1, e,i,j);
    st ret;
    int left = abs(mid-b)+1;
    int r8 = abs(e-mid);
//    cout << "b = " << b << " e = " << e << endl;
//    cout << left << " = left r8 = " << r8 << endl;
    /// find left side
    if(retL.lenL==left && retL.L == retR.L)
    {
            ret.lenL = retL.lenL + retR.lenL;
    }
    else ret.lenL = retL.lenL;

    ret.L = retL.L;

    /// Find right side
    if(retR.lenR==r8 && retR.R == retL.R)
    {
            ret.lenR = retR.lenR+retL.lenR;
    }
    else ret.lenR = retR.lenR;
    ret.R = retR.R;

///** Finda mx len
    int MAX =max(ret.lenL, ret.lenR);
    MAX = max(MAX, retL.mxlen);
    MAX = max(MAX, retR.mxlen);
    if(retL.R == retR.L)
    {
        MAX = max(MAX, retL.lenR+retR.lenL);
    }
    ret.mxlen = MAX;
    return ret;
}
int main()
{
    int TC, idd = 0;
    scanf("%d",&TC);
    while(TC--){
    int n,c,q;
    sf3(n,c,q);
    memset(tree,0,sizeof(tree));
    for(int i=0; i<n; i++)
    {
        sf(arr[i]);
    }
    build(1,0,n-1);

    printf("Case %d:\n",++idd);
    while(q--){
    int a,b;
    sf2(a,b);
    a--;b--;
    printf("%d\n", query(1,0,n-1,a,b).mxlen);
    }
    }
}
