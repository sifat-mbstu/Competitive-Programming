#include<stdio.h>
int main()
{
int n,b,c,i;
while(scanf("%d",&n)==1)
{
for(i=0;i<n;i++)
    {
    scanf("%d%d",&b,&c);
    if(b>c)
    printf(">\n");
    else if(b<c)
    printf("<\n");
    else 
    printf("=\n");
    }
}
return 0;
}