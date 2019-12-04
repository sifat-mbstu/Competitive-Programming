#include <stdio.h>
int main()
{
    char ara[100],Max;
    int n,i;
    //scanf("%d",&n);
    //for(i=0;i<n;i++){
        scanf("%[^\n]s",ara);
    //}
    n=strlen(ara);
    for (i = n-1; i >= 0 ; i--)
    {
        if(ara[i]!=' '){ara[i]='\0';
        printf("%c ",ara[i]);}
        /*if(Max<ara[i])
        {
            Max=ara[i];
        }*/
    }
    /**printf("%d",Max+26);**/

}
