#include<stdio.h>
#include<string.h>
int main()
{
    char C,str[35],ara[150];
    int i,pos,num,N,len,TEST;
    scanf("%d",&TEST);
    while(TEST--)
    {
        pos=0;
        scanf("%d",&N);
        C=getchar();
        for(i=0; i<N; i++)
        {
            gets(str);
            len = strlen(str);

            if(strcmp(str,"LEFT")==0)
            {
                //pos--;
                ara[i]=1;
            }
            else if(strcmp(str,"RIGHT")==0)
            {
                //pos++;
                ara[i]=0;
            }

            else
            {
                num = str[8]-'0';
                //printf("\nNUM==%d\n",num);
                if(num-1>i)
                {
                    ara[i]=num+2;
                }
                else
                {
                    if(ara[num-1]==1)
                    {
                        //  pos--;
                        ara[i]=1;
                    }
                    else
                    {
                        //pos++;
                        ara[i]=0;
                    }
                }
            }
        }
        for(i=0; i<N; i++)
        {
            if(ara[i]>1)
            {
                if(ara[ara[i]-3]==1)
                {
                    //  pos--;
                    ara[i]=1;
                }
                else if(ara[ara[i]-3]==0)
                {
                    //pos++;
                    ara[i]=0;
                }
            }
        }
        for(i=0; i<N; i++)
        {
            if(ara[i]==0)
            {
                pos++;
            }
            else
            {
                pos--;
            }
        }
        printf("%d\n",pos);
    }
    return 0;
}
