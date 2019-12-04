#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,sum,num,div,Test;
    scanf("%d",&Test);
    while(Test--)
    {
        sum=0;
        scanf("%d%d%d",&a,&b,&c);
        num = a + b;
        div = num;
        while(div!=0)
        {
            div = num / c;
            sum = sum + div;
            a = num % c;
            num = div + a;
        }
        printf("%d\n",sum);
    }
    return 0;
}
