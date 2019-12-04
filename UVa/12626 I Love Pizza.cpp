#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[610],c;
    int num,i,a,A,M,R,G,T,I,ara[800],len,COUNT;
    scanf("%d",&num);
    c=getchar();
    while(num--){
    gets(str);
    COUNT = 0;
    len = strlen(str);
    for(i=0;i<29;i++)
    {
        ara[i]=0;
    }
    for(i=0;i<len;i++)
    {
        a=str[i]-'A';
        //printf("%d",a);
        ara[a]++;
        //printf("%d  ",ara[a]);
    }
    while(ara[0]>=3 && ara[12]>=1 && ara[17]>=2 && ara[6]>=1 && ara[19]>=1 && ara[8]>=1)
    {

        ara[0] = ara[0] - 3;
        ara[12]= ara[12] - 1;
        ara[17]= ara[17] - 2;
        ara[6] = ara[6] - 1;
        ara[19]= ara[19] - 1;
        ara[8] = ara[8] - 1;
        COUNT++;

    }
    printf("%d\n",COUNT);
    }
    return 0;
}
