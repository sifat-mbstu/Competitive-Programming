#include<bits/stdc++.h>
using namespace std;
struct st
{
    int num;
    int mnum;
    bool odd;
    bool even;
}arr[10010];
bool acompare(st lhs, st rhs)
{
    if(lhs.mnum != rhs.mnum)
        return lhs.mnum<rhs.mnum;

    if(lhs.odd && rhs.even) return 1;
    if(lhs.odd && rhs.odd) return lhs.num > rhs.num;
    if(lhs.even && rhs.even) return lhs.num < rhs.num;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n, &m)==2){
    printf("%d %d\n",n,m);
    if(!n && !m)break;
    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%d",&val);
        arr[i].num = val;
        arr[i].mnum = val%m;
        arr[i].odd = (val%2);
        arr[i].even= !(val%2);
    }
    sort(arr,arr+n,acompare);
    for(int i=0; i<n; i++)
    {
        printf("%d\n",arr[i].num);
        arr[i].num = 0;
        arr[i].mnum = 0;
        arr[i].odd = 0;
        arr[i].even= 0;
    }
    }
}
