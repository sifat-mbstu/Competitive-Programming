#include<bits/stdc++.h>
using namespace std;
int cnt;
int to[100];
int arr[2020];
int tree[8080];

void build(int b, int e, int node)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
    build(b,mid,L);
    build(mid+1,e,R);

    tree[node] = tree[L] | tree[R];
    if( (!tree[L] && tree[R]) || (tree[L] && !tree[R])) cnt++;

}

int main()
{

    to[0] = 1;
    for(int i=1; i<14; i++)
    {
        to[i] = to[i-1]*2;
    }
    int TC;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,m;
        scanf("%d %d",&n, &m);
        memset(arr,1,sizeof(arr));
        n = to[n];
        for(int i=0; i<m; i++)
        {
            int v;
            scanf("%d",&v);
            arr[v] = 0;
        }
        cnt = 0;
        build(1,n,1);
        printf("%d\n",cnt);
    }
}
