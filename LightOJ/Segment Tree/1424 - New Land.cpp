#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define inf INT_MAX/3
#define mx 100010
char s[2010][2010];
int cum[2010][2010];
int arr[mx], n, Max;

struct St
{
    int val;
    int id;
} tree[mx*4];

void build(int node, int lo, int hi)
{
    if(lo==hi)
    {
        tree[node].val = arr[lo];
        tree[node].id = lo;
        return;
    }
    
    ll mid = (lo+hi)/2;
    ll L = node*2;
    ll R = L+1;
    
    build(L, lo, mid);
    build(R, mid+1, hi);
    
    if(tree[L].val <= tree[R].val)
    {
        tree[node].val = tree[L].val;
        tree[node].id  = tree[L].id;
    }
    else
    {
        tree[node].val = tree[R].val;
        tree[node].id  = tree[R].id;
    }
}

St query(int node, int qlo, int qhi, int lo, int hi)
{
    if(no_overlap(qlo, qhi, lo, hi))
    {
        St nai;
        nai.val = inf;
        return nai;
    }
    if(total_overlap(qlo, qhi, lo, hi)) return tree[node];
    
    ll mid = (lo+hi)/2;
    int L = node*2;
    int R = L+1;
    St a = query(L, qlo, qhi, lo, mid);
    St b = query(R, qlo, qhi, mid+1, hi);
    
    if(a.val <= b.val) return a;
    else return b;
}

void fun(int st, int en)
{
    if(st>en) return;
    St now = query(1, st, en, 0, n-1);
    int loc = now.id;
    int cur = now.val*(en-st+1);
    fun(st, loc-1);
    fun(loc+1, en);
    Max = max(Max, cur);
}

int main()
{
    int TC, idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int res = 0;
        int m;
        scanf("%d %d",&m, &n);
        for(int j=0; j<m; j++)
        {
            Max = 0;
            scanf("%s",&s[j]);
            
            for(int i=0; i<n; i++)
            {
                if(s[j][i]=='0')
                {
                    if( (j>0) && (s[j-1][i]=='0')) cum[j][i] = cum[j-1][i] + 1;
                    else cum[j][i] = 1;
                }
                else cum[j][i] = 0;
                
                arr[i]= cum[j][i];
            }
            build(1,0,n-1);
            fun(0,n-1);
            res = max(Max, res);
        }
        printf("Case %d: %d\n",++idx, res);
    }
}
