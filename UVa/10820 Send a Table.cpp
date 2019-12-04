///ACCEPTED

///This is a code to find out phi(i) where i is (1 to n)
/// Formula of phi(i) = i * ((p1 - 1)/p1) * ((p2 - 1)/p2) ...... * ((pk - 1)/pk)
// Here, k is number of prime factors

#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
int phi[mx],mark[mx];
int res[mx];
void sievephi(int n)
{
    int i,j;
    for(int i=1; i<=n; i++) {phi[i] = i;}
    phi[1] = 1;
    mark[1] = 1;

    for(int i=2; i<=n; i++)
    {
        if(!mark[i])
        {
            for(j=i; j<=n; j+=i)
            {
                mark[j] = 1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    sievephi(100006);

    res[1]=1;
    for(int i=2; i<51000; i++)
    {
        res[i] = res[i-1]+ (2*phi[i]);
    }
        int n;

    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        printf("%d\n",res[n]);
    }
}
