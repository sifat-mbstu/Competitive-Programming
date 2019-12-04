#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[30], store[200][10],c;
    int i,len, num, N, j, sum, multi, TC;
    scanf("%d",&TC);
    while(TC--)
    {
    scanf("%d",&N);
    c = getchar();
    for(i=0; i<N; i++)
    {
        for(i=0; i<N; i++)
        {
            gets(str);
            len = strlen(str);
            if(len==4) { strcpy(store[i],"L");}
            else if(len==5) { strcpy(store[i],"R");}
            else
            {
                multi = 1; sum = 0;
                for(j= len -1; j>7; j--)
                {
                    num = str[j] - '0';
                    sum += multi*num;
                    multi *= 10;
                }
                if(strcmp(store[sum-1], "L")==0) { strcpy(store[i], "L");}
                else if(strcmp(store[sum-1], "R")==0) { strcpy(store[i], "R");}
            }
        }
    }
    int res = 0;
    for(i=0; i<N; i++)
    {
        if(strcmp(store[i],"L")==0){ res--;}
        else {res++;}
    }
    printf("%d\n",res);
    }
}
