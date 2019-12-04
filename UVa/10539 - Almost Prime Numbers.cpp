#include<bits/stdc++.h>
using namespace std;
unsigned long long ara[2000005] = {0};
unsigned long long range[2000005] = {0};
unsigned long long prime[1000000] = {0};
int main()
{
    long long int n, a, b,m,l,lo,hi,lo_,hi_;
    long long i, j, index,sqr;
    for(i = 4; i<2000000; i+=2)
    {
        ara[i] = 1;
    }
    for(a = 3; a <= 1500; a += 2 )
    {
        if(ara[a] == 0)
        {
            for(b = a*a ; b < 2000000; b += a)
            {
                ara[b] = 1;
            }
        }
    }
    prime[0] = 2;
    a = 1;
    for(i=0; i<2000000; i++)
    {
        if(ara[i] == 0)
        {
            prime[a] = i;
            a++;
        }
        range[i] = a;
    }
    scanf("%lld %lld",&lo,&hi);
    lo_ = floor(sqrt(lo));
    hi_ = floor(sqrt(hi));
    cout << lo_ << " "<< hi_;
   // for(i=lo;i<hi;i++)
    //{
        printf("%lld\n",range[hi_]-range[lo_]);
    //}

    return 0;
}
