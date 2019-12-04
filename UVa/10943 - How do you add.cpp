#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[200][200];
void add()
{
    ll sum = 0,i,j;
    for(i=0; i<=100; i++)
    {
        ara[0][i] = i;
    }
    for(i=1; i<=100; i++)
    {
        for(j=1; j<=100; j++)
        {
            sum += ara[i-1][j];
            sum = sum % 1000000;
            ara[i][j] = sum;
            //cout << sum << endl;
        }
        sum = 0;
    }
}
int main()
{
    add();
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a == 0 && b == 0)
        {
            break;
        }
        cout << ara[a-1][b] << endl;
    }
}
