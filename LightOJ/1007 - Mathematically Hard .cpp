///This is a code to find out phi(i) where i is (1 to n)
/// Formula of phi(i) = i * ((p1 - 1)/p1) * ((p2 - 1)/p2) ...... * ((pk - 1)/pk)
// Here, k is number of prime factors

#include<bits/stdc++.h>
using namespace std;
#define mx 5000006

#define ll unsigned long long
unsigned long long phi[mx];
bool mark[mx];
void sievephi()
{
    for(int i=1; i<=mx; i++) {phi[i] = i;}
    phi[1] = 1;
    mark[1] = 1;

    for(int i=2; i<=mx; i++)
    {
        if(!mark[i])
        {
            for(int j=i; j<=mx; j+=i)
            {
                mark[j] = 1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    sievephi();
    for(int i=1; i<=mx; i++)
    {
        phi[i] = phi[i]*phi[i];
    }
    for(int i=1; i<mx; i++)
    {
        phi[i] = phi[i-1] + phi[i];
    }
    int TC,idx = 0;
    scanf("%d",&TC);
    while(TC--)
    {
        int a,b;
        scanf("%d %d",&a, &b);
        printf("Case %d: %llu\n",++idx,phi[b]-phi[a-1]);
    }
}
