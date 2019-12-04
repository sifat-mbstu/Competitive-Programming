#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cases=0;
    scanf("%d",&cases);
    int i;
    for(i=0; i<cases; i++)
    {
        int x=0,y=0;
        scanf("%d %d",&x,&y);
        int sum=y-x;
        int num=sqrt(sum),result=0;
        if(sum==0)
        {
            result=0;
        }
        else if(num*num==sum)
        {
            result=num*2-1;
        }
        else if(num*num+num<sum)
        {
            result=num*2+1;
        }
        else
        {
            result=num*2;
        }
        printf("%d\n",result);
    }
    return 0;
}
