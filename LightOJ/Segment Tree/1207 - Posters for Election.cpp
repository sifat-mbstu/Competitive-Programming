#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define total_overlap(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define no_overlap(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW
#define mx 200010
int lazy[mx*4];
void update(int node, int b, int e, int i, int j,  int delta)
{
    if(b>e){ return; }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
    if(lazy[node]!=0)
    {
        if(b != e)
        {
            lazy[L] = lazy[node];
            lazy[R] = lazy[node];
            lazy[node] = 0;
        }
    }
    if(no_overlap(i, j, b, e)){ return; }
    if(total_overlap(i, j, b, e))
    {
        lazy[node] = delta;
        if(b!=e)
        {
            lazy[L] = delta;
            lazy[R] = delta;
            lazy[node] = 0;
        }
        return;
    }
    update(L, b, mid, i, j, delta);
    update(R,mid+1, e, i, j,delta);
}
set<int> numbers;
set<int> :: iterator it;
set <int> Set;
void query(int node, int b, int e, int i, int j)
{
    if(b > e) { return; }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;
    if(lazy[node]!=0)
    {
        if(b!=e)
        {
            lazy[L] = lazy[node];
            lazy[R] = lazy[node];
            lazy[node] = 0;
        }
    }
    if(no_overlap(i, j, b, e)) { return ; }
    if(total_overlap(i, j, b, e))
    {
        if(lazy[node]!=0){ Set.insert(lazy[node]); }
        return ;
    }
    query(L, b, mid, i, j);
    query(R, mid+1, e, i, j);
}

int main()
{
    int TC, ind = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n, q, choise;
        int ar1[200010], ar2[200010];
        map <int, int> Map;
        Set.clear(); numbers.clear(); Map.clear();
        scanf("%d",&q);
        int loc1, loc2;
        for(int i=1; i<=q; i++)
        {
            scanf("%d %d",&ar1[i], &ar2[i]);
            numbers.insert(ar1[i]);
            numbers.insert(ar2[i]);
        }
        int cnt = 0;
        for(it = numbers.begin(); it != numbers.end(); it++)
        {
            Map[(*it)] = cnt++;
        }
        n = cnt;
        for(int i=1; i<=q; i++)
        {
            update(1,0, n-1, Map[ar1[i]], Map[ar2[i]], i);
        }
        for(int i=0; i<n; i++)
        {
            query(1, 0, n-1,i, i);
        }
        printf("Case %d: ",++ind);
        cout << Set.size() << endl;
    }
}
