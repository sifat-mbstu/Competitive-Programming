#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else return GCD(b, a % b);
}

int main()
{
    int TC,T,a,b,c,n,lcm,i;
    scanf("%d",&TC);
    while(TC--)
    {
        scanf("%d %d",&a,&c);
        if(a > c){swap(a,c);}
        T = 0;
        n = GCD(a,c);
        //cout << n << endl;
        for(i=a+1; i<=a+n; i++)
        {
            lcm = (a*i)/GCD(a,i);
            if(lcm == c)
            {
                T = 1;
                b = i;
                break;
            }
        }
        if(T) printf("%d\n",b);
        else
        {
            printf("NO SOLUTION\n");
        }
    }
}
