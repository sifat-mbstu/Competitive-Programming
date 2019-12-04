///Nlog(k)
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
int n;
int ar[40005];
int in[40005];
int L[40005];
int I[40005];
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

int LIS()
{
    int i;
    memset(L,0,sizeof(L));
    I[0] = -inf; //
    for( i = 1; i <= n; i++ )
        I[i] = inf;
    int len = 0;
    for( i = 0; i < n; i++ )
    {
        int low, high, mid;
        low = 0;
        high = len;
        while( low <= high )
        {
            mid = ( low + high ) / 2;
            if( I[mid] <= ar[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = ar[i];
        if(len < low)
              len = low;
    }
    return len;
}

int main()
{
//    FO;
    int XX = 0;
    while(1)
    {
        int val;
        n =0;
        while(scanf("%d",&val))
        {
            in[n++] = val;
            if(val<0)break;
        }
        n--;
        int ind=0;
        for(int i=n-1; i>=0; i--)
        {
            ar[ind++] = in[i];
        }
        if(in[0]<0)break;
        if(XX > 0) cout << endl;
        printf("Test #%d:\n",++XX);
        printf("  maximum possible interceptions: %d\n",LIS());
    }
}
