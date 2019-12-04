#include<bits/stdc++.h>
using namespace std;
#define mx 714725
int n,arr[mx], ans[mx];
int res_idx;
int tree[mx*4];
int trev[mx*4];
void build(int b, int e, int node)
{
    if(b<1 || e>n)return;
    if(b==e)
    {
        tree[node] = 1;
        trev[node] = arr[b];
        return;
    }
    int mid = (b+e)/2;
    build(b,mid,node*2);
    build(mid+1,e,node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int vec;
void query(int b, int e, int node, int idx)
{
    int mid = (b+e)/2;
    if(b==e)
    {
        tree[node] = 0;
        return;
    }
    if(idx<=tree[node*2])
    {
        query(b,mid,node*2,idx);
    }
    else
    {
        query(mid+1,e,node*2+1,idx-tree[node*2]);
    }
    tree[node] = tree[node*2]+tree[node*2+1];
}
void que(int b, int e, int node, int idx)
{
    if(b==e)
    {
        vec = node;
        return;
    }
    int mid = (b+e)/2;
    if(idx<=tree[node*2])
    {
        que(b,mid,node*2,idx);
    }
    else
    {
        que(mid+1,e,node*2+1,idx-tree[node*2]);
    }
}
int main()
{
    int j=1;
    for(int i=1; i<1429440; i+=2) {arr[j++] = i;}
    n=j-1;
    build(1,n,1);

    ans[res_idx++] = 1;
    for(int i=2; i<=100000; i++)
    {
//        vec.clear();
        que(1,n,1,i);
        int val = trev[vec];
        ans[res_idx++] = val;
        int kk = 0;
        for(int j=val; j<n; j+=val)
        {
            query(1,n,1,j-kk);
            kk++;
        }
    }
    int TC,IDX = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int given;
        scanf("%d",&given);
        printf("Case %d: %d\n",++IDX, ans[given-1]);
    }
}
