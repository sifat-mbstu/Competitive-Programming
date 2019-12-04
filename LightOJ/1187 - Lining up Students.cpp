#include<bits/stdc++.h>
using namespace std;
#define mx 200010
//int mk[mx];
int arr[mx];
int ans[mx];
int tree[mx*4];
void build(int b, int e, int node)
{
    if(b==e)
    {
        tree[node] = 1;
        return;
    }
    int mid = (b+e)/2;
    build(b,mid,node*2);
    build(mid+1,e,node*2+1);
    tree[node] = tree[node*2]+tree[node*2+1];
}
void update(int b, int e, int qb, int qe, int node)
{
//    cout << b << "=b ... e = " << e << endl;
    if(b>qe || e<qb)
        return;
    if(b>=qb && e<=qe){
//        cout << "b = " << b << " e = " << e << endl;
//        cout << "qb = " << qb << " qe = " << qe << endl;
//    getchar();
//        cout << "here----\n";
        tree[node] = 0;
        return;
    }
    int mid = (b+e)/2;
    update(b,mid,qb,qe,node*2);
    update(mid+1,e,qb,qe,node*2+1);
    tree[node] = tree[node*2]+tree[node*2+1];
}
int fnd(int b, int e, int node, int pos)
{
//    cout << b << "=b ... e = " << e << endl;
//    getchar();
    if(b==e) return b;
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
//    cout << tree[L] << "=tree[left] ... pos = " << pos << endl;

    if(pos<=tree[L])
    {
        return fnd(b,mid,L,pos);
    }
    else return fnd(mid+1,e,R,pos-tree[L]);
}
int main()
{
    int TC,idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        memset(tree,0,sizeof(tree));
        int n;
        scanf("%d",&n);
        build(1,n,1);
        for(int i=1; i<=n ; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=n; i>=1; i--)
        {
            int val = i - arr[i];

//            cout <<"val = " << val << endl;
            ans[i] = fnd(1,n,1,val);
//            cout << "ans = " << ans[i] << endl;
//            getchar();
            update(1,n,ans[i],ans[i],1);
        }
        printf("Case %d: %d\n",++idx,ans[1]);
    }

}
