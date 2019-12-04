#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a1[12], a2[12],i;
    a1[0] = 6;
    a1[1] = 35;
    a2[0] = 8;
    a2[1] = 49;
    for(i=2;i<10;i++)
    {
        a1[i] = a1[i-1] * 6 - a1[i-2];
        a2[i] = a2[i-1] * 6 - (a2[i-2]-2);
    }
    for(i=0;i<10;i++)
    {
        printf("%10lld%10lld\n",a1[i],a2[i]);
    }
}
