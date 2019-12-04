#include<stdio.h>
#include<string.h>
int main()
{
    int test,i,j,x,length,max,l,k,ara[1000],a;
    char str[1000];
    scanf("%d",&test);
    for(i=1;i<=test;i++){
        max=0,x=0;
        getchar();
    gets (str);
    length=strlen(str);
    printf("length=%d\n",length);
    for(j=0;j<length;j++){
            a=0;
        if(str[j]==32){continue;}
        else {
                if(str[j+1]==32 && j!=length-1){
                        a=str[j]-'0';
                        ara[x]=a;
                            x++;}
                else{
                    while(str[j]!=32 && j!=length){
                        a=a*10+str[j]-'0';
                        j++;
                    }
                        ara[x]=a;
                        x++;
                        j--;
                }
        }
        for(l=0;l<x;l++){
            if(max<ara[l]){
                max=ara[l];
            }
        }

        /*
            k=j;
            while(str[j+1]!=32){
                    k=j;
            if((str[j+1])!=32){str[k]=(str[k]-'0')*10+(str[j+1]-'0')+48;}
            printf("str[k]=%d\n",str[k]);
            j++;
            }
        if(max<(str[k]-'0')){
            max=str[k]-'0';
        }
        //printf("str[%d]=%d max=%d\n",k,str[k]-48,max);*/
    }
    printf("Case %d: %d\n",i,max);
}
return 0;
}
