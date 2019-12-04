#include<bits/stdc++.h>
using namespace std;
#define mx 30000010
int arr[mx],cum[mx];
int main()
{

    for(int i=1; i<mx; i++)
    {
        for(int j=i; i+j<mx; j+=i)
        {
            int val = ((i+j) ^ (j));
            if( val == i)
            {
                arr[i+j]++;
            }
        }
    }

    for(int i=1; i<mx; i++)
    {
        cum[i] = cum[i-1]+arr[i];
    }

    int tc,cs=0;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",++cs,cum[n]);
    }
}
