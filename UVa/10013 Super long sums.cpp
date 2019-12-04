#include<bits/stdc++.h>
using namespace std;
#define ll long long
int sum[1000010],ara[1000010] ;
int main()
{
    //freopen("out.txt", "w", stdout);
    ll n, carry = 0,i,num=0,TC;
    bool cq = 0;
    scanf("%lld",&TC);
    while(TC--){
    if(cq) printf("\n");
    num=0, carry = 0;
    scanf("%lld",&n);
    for(i=0; i<n; i++)
    {
        int a, b;
        scanf("%d %d",&a, &b);
        ara[i] = a+b;
    }
    for(i=n-1; i>=0; i--)
    {
        num = ara[i] + carry;
        sum[i] = num % 10;
        num /= 10;
        carry = num;
    }
    if(carry!=0) cout <<carry;
    for(i=0; i<n; i++)
    {
        printf("%d",sum[i]);
    }
    printf("\n");
    cq = 1;
    }
}
