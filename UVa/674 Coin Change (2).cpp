#include<bits/stdc++.h>
using namespace std;
int sum=0;
int coin_change(int n)
{
    printf("n = %d\n",n);
    if(n==0){return 1;}
    if (n<0){return 0;}
    sum = coin_change(n-1) + coin_change(n-5) + coin_change(n-10)+ coin_change(n-25) + coin_change(n-50);
    printf("sum = %d\n",sum);
}

int main()
{
    int n;
    scanf("%d",&n);
    coin_change(n);
    printf("\n%d",sum);
}
