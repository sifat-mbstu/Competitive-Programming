#include<bits/stdc++.h>
int main()
{
    int test,len,N,i,j,p,q;
    char str[1000010],ch_1,ch_2,CH[50],sp;
    scanf("%d",&test);
    while(test--)
    {
        sp=getchar();
        gets(str);
        len=strlen(str);
        scanf("%d",&N);
        for(i='A',j=0;i<='Z';i++,j++)
        {CH[j]=i;}
        for(i=0;i<N;i++){
            sp = getchar();
            ch_1 = getchar();
            sp = getchar();
            ch_2 = getchar();
            p=ch_2-'A';
            CH[p]=ch_1;
            for(j=0;j<26;j++)
            {
                q=CH[j]-'A';
                printf("ch==%d\n",q);
                if(p==q){CH[j]=ch_1;}
            }
            //printf("%c %c",ch_1,ch_2);
        }
            for(j=0;j<len;j++)
            {
                p=str[j]-'A';
                if(p<26){printf("%c",CH[p]);}
                else{printf("%c",str[j]);}
            }
            printf("\n");
    }
    return 0;
}

