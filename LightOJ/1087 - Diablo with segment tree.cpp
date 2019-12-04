#include<bits/stdc++.h>
using namespace std;
#define MEM(a,val) memset(a,val,sizeof(a))
#define mx 200010
int n,q;
int arr[mx];
struct st
{
    int v, idx;
} tree[mx*4];
void build(int node, int b, int e)
{
    if(b==e)
    {
        if(b<=n)tree[node]= {1,arr[b]};
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    build(L,b,mid);
    build(R,mid+1,e);

    tree[node].v = tree[L].v + tree[R].v;
}
void fnd(int node, int b, int e, int v)
{
    if(b==e)
    {
        tree[node].v = 0;
        printf("%d\n",tree[node].idx);
        return;
    }
    int mid = (b+e)/2;
    int L = 2*node;
    int R = L+1;

    if(tree[L].v>=v)  fnd(L, b, mid, v);
    else fnd(R,mid+1,e,v-tree[L].v);
    tree[node].v = tree[L].v + tree[R].v;
}
void update(int node, int b, int e, int i, int j, int val)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j)
    {
        tree[node] = {1,val};
        return;
    }
    int mid = (b+e)/2;
    int L = 2*node;
    int R = L+1;

    update(L, b, mid, i, j, val);
    update(R, mid+1,e,i,j,val);

    tree[node].v = tree[L].v + tree[R].v;
}
int main()
{
    int TC,cas=0;
    scanf("%d",&TC);
    while(TC--)
    {
        MEM(tree,0);
        MEM(arr,0);
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,mx);
        int cur = n;
        printf("Case %d:\n",++cas);
        while(q--)
        {
            char s[10];
            int a;
            scanf("%s %d",s,&a);
            if(s[0]=='c')
            {
                if(cur < a) printf("none\n");
                else {fnd(1, 1, mx, a);
                cur--;}
            }
            else
            {
                cur++;
                n++;
                update(1,1,mx,n,n,a);
            }
        }
    }
}
