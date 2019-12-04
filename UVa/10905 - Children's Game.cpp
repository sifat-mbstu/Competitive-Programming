#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    char str[60][60],temp[60];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    for(i=0 ; i < n-1; i++)
    {
        for(j=i+1; j < n; j++)
        {
            if(strcmp(str[i],str[j])> 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    for(i=n-1;i>=0;i--)
    {
        printf("%s",str[i]);
    }
    printf("\n");
}
