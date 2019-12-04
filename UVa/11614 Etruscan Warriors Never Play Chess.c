#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long rows,worriors,sq,Case;
    scanf("%llu",&Case);
    while(Case--)
    {
        scanf("%llu",&worriors);
       // worriors = (worriors*8)+1;
        rows = sqrt((worriors*8)+1);
        rows=(rows-1)/2;
        printf("%llu\n",rows);
    }
    return 0;
}
