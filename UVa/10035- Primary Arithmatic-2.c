#include<stdio.h>
int main()
{
    unsigned long long int on,a,b,ar[100],br[100],i,g,h,sum,count,k,rem;
    while((scanf("%llu%llu",&a,&b))==2){
        if(a==0 && b==0)
        {
            break;
        }
    for(i=0; i<=90; i++)
        {
            ar[i]=br[i]=0;
        }
        i=0;
    while(a!=0){
        rem=a%10;
        ar[i]=rem;
        a=a/10;
        i++;
    }
    g=i,i=0;
    while(b!=0){
        rem=b%10;
        br[i]=rem;
        b=b/10;
        i++;
    }
    h=i;
    if(g>h){i=g;}
    else i=h;
   // printf("i==%llu\n",i);
    on=0,count=0;
    for(k=0;k<i;k++){
        sum=ar[k]+br[k]+on;
        if(sum>9){
            on=1;
            count++;
        }
        else{on=0;}
        sum=0;
    }
       if(count==0)
        {
            printf("No carry operation.\n");
        }
                else if(count==1)
        {
            printf("%llu carry operation.\n",count);
        }
        else
        {
            printf("%llu carry operations.\n",count);
        }
    }
    return 0;
}
