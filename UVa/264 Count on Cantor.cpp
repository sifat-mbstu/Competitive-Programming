#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, prev,dif,n1,n2;
    while(scanf("%d",&n)==1)
    {
        i = sqrt(n);
        for( ; i < 10000; i++)
        {
            k = (i * (i + 1)) / 2;
            if(k >= n)
            {
                prev = (i * (i - 1) ) / 2;
                break;
            }
            else if(k == n)
            {
                prev = k;
                break;
            }
        }
        dif = n - prev;
        //cout << i << endl;
        if(i%2 == 0)
        {
            n2 = i - dif + 1;
            n1 = dif;
        }
        else
        {
            n2 = dif ;
            n1 = i - dif + 1;
        }
        printf("TERM %d IS %d/%d\n",n,n1,n2);
    }
}
