#include <bits/stdc++.h>
using namespace std;
#define SIZE 3100
int status [SIZE];
void sieve()
{
    long long int i,j;
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
    status[1] = 1;
}
int main()
{
    int n,alpha[210],i,k,l,TC;
    sieve();
    char str[2010],c;
    scanf("%d",&TC);
    c = getchar();
    for(l =1 ;l<= TC; l++){
    gets(str);
    k = 0;
    memset(alpha, 0, sizeof(alpha));
    int len = strlen(str);
    for (i =0; i<len; i++)
    {
        alpha[str[i]]++;
    }
    for(i=0; i<200;i++){
    if(alpha[i] > 0)
    {
        //printf("i = %d  alpha[i] = %d\n",i,alpha[i]);
        if(status[alpha[i]] == 0)
        {
            if(k==0){printf("Case %d: ",l);}
            k++;
            printf("%c",i);
        }
    }
    }
    if(k == 0){ printf("Case %d: empty\n",l);}
    else{ printf("\n"); }
    }
}
