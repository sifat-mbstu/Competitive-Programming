#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a[3000];
    int n,i,j,carry,m,x;
    while(scanf("%d",&n)==1)
    {
        a[0]=1;
        m=1;
        carry = 0;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<m; j++)
            {
                x = a[j]*i+carry;
                a[j]=x%10;
                carry = x/10;
            }
            while(carry!=0)
            {
                a[m]=carry%10;
                carry = carry/10;
                m++;
            }
        }
        printf("%d!\n",n);
        for(i=m-1; i>=0; i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
