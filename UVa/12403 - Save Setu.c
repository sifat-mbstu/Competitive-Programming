#include<stdio.h>
#include<string.h>
int main()
{
    char str_1[10],str_2[10];
    int i,n,tot=0,j,sum,num,a,t,on;
    scanf("%d",&t);
    getchar();
    while(t--){
    gets(str_1);
    if(strcmp(str_1,"report")==0){on=1;}
    else{
    n=strlen(str_1);
    printf("n--%d\n",n);

    sum=0;
    a=1;
    for(i=n-1;i>=7;i--)
    {
        printf("%c\n",str_1[i]);
        num = str_1[i]-'0';
        printf("num--%d\n",num);
        sum=sum + num*a;
        a=a*10;
    }
    printf("%d\n",sum);
    if(on){
    printf("tot=%d\n",tot);
    }
    else {}
    }
    }
    return 0;
}
