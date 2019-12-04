#include<stdio.h>
int main()
{
    int x,c,v,d,k,l,N,a,Test,count,b,i;
    while((scanf("%d",&Test))==1)
    {
        if(Test==0)break;
        i=v=x=l=c=0;
        for(k=Test; k>0; k--)
        {
            N=k;
            while(N>0)
            {
                if(N<=3)
                {
                    N-=1,i++;
                }
                else if(N<=4)
                {
                    N-=4,i++,v++;
                }
                else if(N<=8)
                {
                    N-=5,v++;
                }
                else if(N<=9)
                {
                    i++,x++,N-=9;
                }
                else if(N<=39)
                {
                    N-=10,x++;
                }
                else if(N<=49)
                {
                    N-=40,x++,l++;
                }
                else if(N<=89)
                {
                    N-=50,l++;
                }
                else if(N<=99)
                {
                    N-=90,x++,c++;
                }
                else
                {
                    N-=100,c++;
                }
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",Test,i,v,x,l,c);
    }
    return 0;
}
