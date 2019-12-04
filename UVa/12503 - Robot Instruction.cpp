#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[20],C;
    int N,ara_1[1000],ara_2[1000],pos=0,i,num;
    scanf("%d",&N);
    C=getchar();
    for(i=0; i<N; i++)
    {
        gets(str);
        ara_2[i]=-1;
        if(strcmp(str,"LEFT")==0)
        {
            ara_1[i]=0;
            pos--;
        }
        else if(strcmp(str,"RIGHT")==0)
        {
            ara_1[i]=1;
            pos++;
        }
        else
        {
            num = str[8]-'0';
            ara_2[i]=num-1;
        }
        //printf("\ntest pos 1 == %d\n",pos);
    }
    sort ( ara_2 , ara_2+N);
    for(i=0; i<N; i++)
    {
        if(ara_2[i]!=-1)
        {
            printf("\n%d",ara_1[ara_2[i]]);
            if(ara_1[ara_2[i]]==1)
            {
                pos--;
                ara_1[i]=1;
            }
            else
            {
                pos++;
                ara_1[i]=0;
            }
                    //printf("\ntest pos 2== %d\n",pos);
        }
    }
    printf("\n%d",pos);
}
