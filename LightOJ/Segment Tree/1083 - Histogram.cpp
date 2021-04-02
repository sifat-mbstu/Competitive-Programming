#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mx 30100
int n;
int arr[mx];
struct st
{
    int val,idx;
}tree[mx*4];
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = {arr[b],b};
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    build(L,b,mid);
    build(R,mid+1,e);

    tree[node].val = min(tree[L].val,tree[R].val);
    tree[node].idx = (tree[L].val<=tree[R].val ? tree[L].idx : tree[R].idx);
}

st query(int node, int b, int e, int i, int j)
{
    if(e<i || b>j) return {inf,0};
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    st ret1 = query(L, b, mid, i,j);
    st ret2 = query(R, mid+1,e,i,j);
    return ( ret1.val<=ret2.val ? ret1 : ret2);
}

int fnd(int b, int e)
{
    if(b>e) return 0;
    st now = query(1,0,n-1,b,e);
    int v = now.val * (e-b+1);
    int idx = now.idx;
    int v1 = fnd(b,idx-1);
    int v2 = fnd(idx+1,e);
    return max(v, max(v1,v2));
}

int main()
{
    int TC,cas=0;
    scanf("%d",&TC);
    while(TC--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,0,n-1);
        int ans = fnd(0,n-1);
        printf("Case %d: %d\n",++cas,ans);
    }
}
