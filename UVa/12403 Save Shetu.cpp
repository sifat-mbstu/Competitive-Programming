#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Test,len,sum=0,num,TC;
    char str[12],C;
    cin >> TC;
    for(int x = 1; x <= TC; x++){
    scanf("%d",&Test);
    sum=0;
    C= getchar();
    bool te = 0;
    while(Test--)
    {
        scanf("%s",str);
        len=strlen(str);
        if(strcmp(str,"report")!=0)
        {
            scanf("%d",&num);
            sum = sum + num;
        }
        else{
        if(!te) { printf("Case %d:\n",x);}
        printf("%d\n",sum);
        te = 1;
        }
    }
    }
    return 0;
}
