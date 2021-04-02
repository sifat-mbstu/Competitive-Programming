#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ara[mx];
int tree[mx*4];
int uni[mx];
int noya,key;

struct st
{
    int fst,sec, idx, res;
} brr[mx],tmp;

void build(int node,int i,int j)
{
    int Mid,R,L;
    if(i>j)
        return ;
    if(i==j)
    {
        tree[node]=0;
        return ;
    }
    Mid = (i+j)/2;
    L=2*node;
    R=L+1;
    build(L,i,Mid);
    build(R,Mid+1,j);
    tree[node]= tree[L]+tree[R];
}

void update(int node,int b,int e, int i)
{
    int Mid,L,R,p,q;
    if(i<b || i>e) return;
    if(b==i && e==i)
    {
        if(noya == -1) tree[node] = 0;
        else tree[node]=1;
        return ;
    }
    Mid=(b+e)/2;
    L=node*2;
    R=node*2+1;
    update(L,b,Mid,i);
    update(R,Mid+1,e,i);
    tree[node]=tree[L]+tree[R];
}

int query(int node,int b,int e, int i, int j)
{
    int Mid,L,R;
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node];
    Mid=(b+e)/2;
    L=node*2;
    R=node*2+1;
    int ret1 =query(L,b,Mid,i,j);
    int ret2 =query(R,Mid+1,e,i,j);
    return ret1+ret2;
}
bool cmp1(st const& lhs, st const& rhs)
{
    if (lhs.sec != rhs.sec)
        return lhs.sec < rhs.sec;
}
bool cmp2(st const& lhs, st const& rhs)
{
    if (lhs.idx != rhs.idx)
        return lhs.idx < rhs.idx;
}
int main()
{
    int tc, ii=0;
    cin >> tc;
    while(tc--)
    {
        int i,j,k,l,m,n,t,q;
        int last[mx];
        memset(last, -1, sizeof(last));
        scanf("%d%d",&n,&q);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&ara[j]);
        }
        build(1,1,n);

        for(i=1; i<=q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            brr[i].fst = x;
            brr[i].sec = y;
            brr[i].idx = i;
        }
        sort(brr+1, brr+q+1, &cmp1);
        j = 1;
        for(i=1; i<=n; i++)
        {
            if(last[ara[i]] == -1)
            {
                noya = 1;
                update(1,1, n, i );
                uni[i] = 1;
            }
            else
            {
                uni[i] = 1;
                uni[last[ara[i]]] = 0;
                noya = -1;
                update(1, 1,n,last[ara[i]]);
                noya = 1;
                update(1, 1,n,i);
            }
            last[ara[i]] = i;
            while(brr[j].sec == i)
            {
                brr[j].res = query(1,1,n,brr[j].fst,i);
                j++;
            }
            if(j==q+1)
                break;
        }
        sort(brr+1, brr+q+1, &cmp2);
        printf("Case %d:\n",++ii);
        for(i=1; i<=q ; i++)
        {
            printf("%d\n", brr[i].res);
        }

    }
}
