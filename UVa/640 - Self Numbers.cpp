#include<bits/stdc++.h>
using namespace std;
#define maxx 1000100
int ara[maxx];
int sum_digit(int num)
{
    int sum = 0;
    while(num!=0)
    {
        int a = num % 10;
        sum += a;
        num /= 10;
    }
    return sum;
}
void self()
{
    int i,j;
    for(i=1;i<=maxx;i++)
    {
        j = i;
        if(ara[i] == 0)
        {
            while(j <= maxx){
            j = sum_digit(j)+j;
            if(ara[j] == 1){break;}
                ara[j] = 1;
            }
        }
    }
}

int main()
{
    int i;
    self();
    for(i=1;i<=1000000;i++)
    {
        if(ara[i]==0)
        {
            printf("%d\n",i);
        }
    }
}
