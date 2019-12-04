#include<bits/stdc++.h>
using namespace std;
#define SIZE 10000

long int status[SIZE];
void sieve()
{
    long int i,j;
    for(i=0; i<SIZE; i++) status[i]= 0;
    long long int sq = sqrt(SIZE);
    for(i=4; i<=SIZE; i+=2) status[i] = 1;
    for(i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(j=2*i; j<=SIZE; j+=i) status[j]=1;
        }
    }
    status[1] = 0;
}

int main()
{
    char str[30];
    long int sum,n,i,len;
    sieve();
    while(gets(str))
    {
        sum = 0;
        //printf("Enter a number to check goldbach: ");
        len = strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                sum = sum + (str[i] - 'A' + 27);
            }
            if(str[i]>='a' && str[i]<='z')
            {
                sum = sum + (str[i] - 'a' + 1);
            }
        }
        if(status[sum]==0)
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}
