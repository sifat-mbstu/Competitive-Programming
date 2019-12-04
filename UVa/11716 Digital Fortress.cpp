#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10000],C;
    int len,i,num,j,Test;
    float a,b;
    scanf("%d",&Test);
    C = getchar();
    while(Test--)
    {
        gets(str);
        len = strlen(str);
        a = float(len);
        b=sqrt(a);
        if((b-(int)b)!=0)
        {
            printf("INVALID\n");
        }
        else
        {
            num = int(b);
            //printf("num=%d\n",num);
            for(i=0,j=0; j<len; i+=num,j++)
            {
                if(i>=len)
                {
                    i=i-len+1;
                }
                printf("%c",str[i]);
                //if(i>=len){ i=i-len; printf("i=%d\n",i);}
            }
            printf("\n");
        }
    }
    return 0;
}
