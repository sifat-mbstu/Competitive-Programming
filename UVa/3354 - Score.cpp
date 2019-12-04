#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000],c;
    int i,k,len,sum,TC;
    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {
    gets(str);
    len = strlen(str);
    k = sum =0;
    for(i=0;i<len;i++)
    {
        if(str[i]=='O')
        {
            k++;
            sum += k;
        }
        else{k=0;}
    }
    printf("%d\n",sum);
    }
}
