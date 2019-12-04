#include<bits/stdc++.h>
using namespace std;
#define mx 100100
int tree[mx*4];
int lazy[mx*4];
char s[2*mx];
void reset()
{
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
}
int what(char ch)
{
    int a = ch - '0';
    return a;
}
void build(int node, int b, int e)
{
    if(b==e)
    {
        int v = what(s[b]);
        tree[node] = v;
        return;
    }
    int mid = (b+e)/2;
    int L = 2*node;
    int R = L+1;
    build(L,b,mid);
    build(R,mid+1,e);
}
void update(int node, int b, int e, int i, int j)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j)
    {
        lazy[node]++;
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
    update(L, b, mid, i,j);
    update(R,mid+1,e, i,j);
}
int query(int node, int b, int e, int idx, int pro)
{
//    printf("b=%d e=%d\n",b,e);
    if(b==e)
    {
        int cur = pro+lazy[node];
        if(cur%2) return !(tree[node]);
        else return tree[node];
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
    if(idx<=mid) query(L, b, mid, idx, pro+lazy[node]);
    else query(R, mid+1, e, idx, pro+lazy[node]);
}
int main()
{
    int TC,q,n,idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        reset();
        scanf("%s",s);
        n = strlen(s);
        build(1,0,n-1);
        for(int i=0; i<n*4; i++)
//            printf("tree[%d] = %d\n",i,tree[i]);
        scanf("%d",&q);
        printf("Case %d:\n",++idx);
        while(q--)
        {
            char ss[12];
            int a,b;
            scanf("%s",ss);
            if(ss[0]=='I')
            {
                scanf("%d %d",&a, &b);
                a--;b--;
                update(1,0,n-1,a,b);
            }
            else
            {
                scanf("%d",&a);
                a--;
                int ans = query(1,0,n-1,a, 0);
                printf("%d\n",ans);
            }

        }
    }
}
