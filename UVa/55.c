#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char n[1000];
    long long int num, len, odd, even, count, rem, div;
    while(gets(n))
    {
        even =0;
        odd = 0;
        count=0;
        len = strlen(n);
        num = atoi(n);
        if(num==0)
        {
            break;
        }
        while(num>0)
        {
            rem = num % 10;
            num = num / 10;
            count++;
            if(count%2==0)
            {
                even = even + rem;
            }
            else
            {
                odd = odd + rem;
            }
        }
        div = odd - even;
        if(div%11==0)
        {
            printf("%s is a multiple of 11.\n", n);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",n);
        }
    }
    return 0;
}
