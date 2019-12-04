#include<bits/stdc++.h>
using namespace std;

int sz;
int DP[50][3][3];
int fun(int pos, int prev,int flag)
{
    if(pos==sz)
    {
        if(flag) return 1;
        return 0;
    }
    if(DP[pos][prev][flag]!=-1) return DP[pos][prev][flag];
    int low = 0, hi = 1;
    if(prev)
        hi = 0;
    int sum = 0;
    for(int i=low; i<=hi; i++)
    {
        sum += fun(pos+1, i, (flag|i));
    }
    return DP[pos][prev][flag] = sum;
}

void path(int pos, int prev, int flag, int x)
{
    if(pos==sz || x==0)
    {
        return ;
    }
    int num;
    int low =0, hi =1;
    if(prev) hi =0;
    for(int i=low; i<=hi; i++)
    {
        num = fun(pos+1,i,flag|i);
        if(x <= num)
        {
            if(flag|i) printf("%d",i);
            return path(pos+1, i, (flag|i), x);
        }
    x-=num;
    }
}

int main()
{
    sz = 44;
   // fun(0,0,0);
    int TC, ind=0;
    cin >> TC;
    memset(DP,-1,sizeof(DP));
    while(TC--)
    {
        int x;
        scanf("%d",&x);
        printf("Case %d: ",++ind);
        path(0,0,0,x);
        printf("\n");
    }
}
