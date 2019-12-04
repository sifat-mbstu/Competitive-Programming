#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,sum ,div,ori;

    while(scanf("%d %d",&n, &k)==2)
    {
    sum = 0;
    ori = n;
    div = n / k;
    while(div!=0)
    {
        div = n / k;
        sum += div;
        n = div + (n%k);
    }
    printf("%d\n",sum + ori);
    }
}
