#include<stdio.h>
#include<math.h>
#define N 1000000
///Since value can be up to 1000000
int primesTable[N];

void SieveOfEratosthenes()
{
    int i = 2;
    for(; i <= N; ++i)

        primesTable[i] = 1;

    primesTable[0] = primesTable[1] = 0;

    int len = sqrt(N);

    for(i = 2; i <= len; ++i)
    {
        if(primesTable[i])
        {
            for( int k = i * i; k <= N; k += i )
                primesTable[k] = 0;
        }
    }
    primesTable[2] = 0;
}

int main()
{
    int n;
    SieveOfEratosthenes();
    while(scanf("%d", &n) && n)
    {
        for(int a = 3; a < n; ++a)
        {
            if( primesTable[a] )
            {
                int b = n - a;

                if( primesTable[b] )
                {
                    printf("%d = %d + %d\n", n, a, b);
                    break;
                }
            }
        }
    }
    return 0;
}
