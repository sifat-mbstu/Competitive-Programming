#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[120],c;
    int i,len,sum,Case,j;
    scanf("%d",&Case);
    c = getchar();
    for(j=1; j<=Case; j++)
    {
        gets (str);
        len = strlen(str);
        sum = 0;
        for(i=0; i<len; i++)
        {
            if(str[i]=='a' || str[i]=='d' || str[i]=='g' || str[i]=='j' || str[i]=='m' ||
                    str[i]=='p' || str[i]=='t' || str[i]=='w' || str[i]==' ')
            {
                sum++;
                //printf("1\n");
            }
            else if(str[i]=='b' || str[i]=='e' || str[i]=='h' || str[i]=='k' || str[i]=='n' ||
                    str[i]=='q' || str[i]=='u' || str[i]=='x')
            {
                sum+=2;
                //printf("2\n");
            }
            else if(str[i]=='c' || str[i]=='f' || str[i]=='i' || str[i]=='l' || str[i]=='o' ||
                    str[i]=='r' || str[i]=='v' || str[i]=='y')
            {
                sum+=3;
                //printf("3\n");
            }
            else if(str[i]=='s' || str[i]=='z')
            {
                sum+=4;
                //printf("4\n");
            }
        }
        printf("Case #%d: %d\n",j,sum);
    }
    return 0;
}
