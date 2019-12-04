#include<bits/stdc++.h>
using namespace std;

long long int prime[100],ara[1020];
int main()
{
    long long int i,j;
    for(i=0; i<1050; i++)
    {
        ara[i] = 0;
    }
    for(i=4; i<1050; i+=2)
    {
        ara[i] = 1;
    }
    for(i=2; i<32; i++)
    {
        if(ara[i]==0)
        {
            //cout << "\ni == " << i;
            for(j=i*i; j<1050; j+=i)
            {
                ara[j] = 1;
            }
        }
    }
    prime[0] = 1;
    j = 1;
    for(i=2; i<1050; i++)
    {
        if(ara[i]==0)
        {
            prime[j] = i;
            j++;
        }
    }
    long long int N, C, D ;
    while(scanf("%lld %lld",&N, &C)==2)
    {

        for(i=0; ; i++)
        {
            // cout << prime[i] << endl;
            if(prime[i]>N)
            {
                break;
            }
        }
        long long int len = i;
        if(len %2 ==0)
        {
            D = C*2;
        }
        else
        {
            D = (C*2) - 1;
        }

        long long int ini;
        if(len%2 != 0) ini = (len/2 + 1) - (D/2) -1;
        else  ini = (len/2) - (D/2) ;
        long long int fin = ini + D ;
        if(ini<0)
        {
            ini = 0;
        }
        printf("%lld %lld:",N,C);
        for(i=ini; i<fin; i++)
        {
            if(prime[i] > N)
            {
                break;
            }
            printf(" %lld",prime[i]);
        }
        printf("\n\n");
        //cout << i;
        /*for(i=0;i<j;i++)
        {
            cout << prime[i] << endl ;
        }*/
    }
}
