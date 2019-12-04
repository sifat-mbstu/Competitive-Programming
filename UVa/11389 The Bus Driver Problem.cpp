#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
    unsigned long long int i,j,n,d,r,morn[1000],even[1000],sum[1000],SUM;
    while(scanf("%llu %llu %llu",&n,&d,&r)==3)
    {
        for(i=0;i<=100;i++)
        {
            sum[i] = 0;
        }
        SUM = 0;
        if( !n && !d && !r) {break;}
    for(i=0;i<n;i++)
    {
        scanf("%llu",&morn[i]);
    }
    sort(morn, morn+n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&even[i]);
    }
    sort(even, even+n);
    j = n-1;
    for(i=0;i<n;i++)
    {
        sum[i] = morn[i] + even[j];
        if(sum[i] > d) {SUM += sum[i] - d;}
        j--;
    }

    printf("%lld\n",SUM*r);
    }
}
