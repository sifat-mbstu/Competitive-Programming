#include<bits/stdc++.h>
using namespace std;
int N = 10100, status[6000], primes[5000];
int main()
{
    int i, j, sqrtN,n;
    for( i = 2; i <= N >> 1; i++ ) status[i] = 0;
    sqrtN = int( sqrt((double)N) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i>>1] == 0 )
        {
            for(j = i * i; j <= N; j += i + i)
            {
                status[j>>1] = 1;
            }
        }
    }

    status[0] = 0;
    int k = 0;
    for( i = 1; i <= N; i += 2 )
    {
        if( status[i>>1] == 0 )
            if(i!=1)
            {
                primes[k++] = i;
            }
            else
            {
                primes[k++] = i+1;
            }
    }
    while(cin >> n)
    {
        if(!n) break;
        int sum = 0, cnt = 0;
        int x = 0;
        for(i=0; i<k; i++,x = i)
        {

            if(n < primes[i])
            {
                break;
            }
            sum += primes[i];
            if(sum < n)
            {
                while(sum < n)
                {
                    sum += primes[++x];

                }
            }
            if(sum > n)
            {
                while(sum > n && sum > 0)
                {
                    if(sum > primes[x])sum -= primes[x--];
                }
            }

            if(sum == n)
            {
                cnt++;
            }
            sum = 0;
        }
        cout << cnt << endl;
    }
}

