#include <stdio.h>
int main()
{
    int i,j,k,n,N,MAX=0;
    char num[10005];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        getchar();
        gets(num);
        printf("%d",strlen(num));

        //printf("Case %d: %d\n",i,MAX);
    }
    return 0;
}
