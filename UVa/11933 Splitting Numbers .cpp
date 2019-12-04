#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll to[34];
int main()
{
    to[0] = 1;
    for(int i=1; i<33; i++)
    {
        to[i] = to[i-1] * 2;
    }
    ll n;
    while(scanf("%lld",&n)==1){
            if(!n)break;
    bool flag = 1;
    ll s1=0, s2=0;
    for(int i=0; i<32; i++)
    {
        if(flag)
        {
            if(n & (1<<i))
            {
                s1 += to[i];
            flag = !flag;
            }
        }
        else
        {
            if(n & (1<<i))
            {
                s2 += to[i];
            flag = !flag;
            }
        }
    }
    printf("%lld %lld\n",s1,s2);
    }
}
