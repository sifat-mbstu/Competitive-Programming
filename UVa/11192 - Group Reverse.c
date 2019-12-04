#include <stdio.h>
#include <string.h>
int main()
{
    int test,i,N,len,j,mult;
    char str[1000],c;
    while(scanf("%d",&N)==1)
    {
    mult=1;
    if(N==0){break;}
    c = getchar ();
    gets(str);
    len = strlen(str);
    test = len / N;
    if(N==1){
        for(i=len-1;i>=0;i--)
            {
                printf("%c",str[i]);
            }
    }
    else{
    for(i=1;i<=N;i++)
    {
        mult = i * test;
        for(j=mult-1;j>(mult-test-1);j--)
        {
            printf("%c",str[j]);
        }
    }
    }
    printf("\n");

    }
    return 0;
}
