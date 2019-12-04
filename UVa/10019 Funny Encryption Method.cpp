#include<bits/stdc++.h>
using namespace std;
int main()
{
    int deci, hexa, N, b1,b2,TC;
    scanf("%d",&TC);
    while(TC--)
    {
    scanf("%d",&N);
    b1 = b2 = 0;
    deci = hexa = N;
    while(deci!=0)
    {
        if(deci % 2) {b1++;}
        deci /= 2;
    }

    while(hexa !=0)
    {
        deci = hexa %10;
        while(deci!=0)
        {
            if(deci % 2) {b2++;}
            deci /= 2;
        }
        hexa = hexa/10;
    }
    printf("%d %d\n",b1,b2);
    }
}
