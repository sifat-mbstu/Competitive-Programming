#include<bits/stdc++.h>
using namespace std;
int main()
{
    char slogan[150],c,str[49][150];
    int i,j,N,Q;
    scanf("%d",&N);
    c = getchar();
    for(i=0;i<N*2;i++)
    {
        gets(str[i]);
    }
    scanf("%d",&Q);
    c = getchar();
    for(i=0;i<Q;i++)
    {
        gets(slogan);
        for(j=0;j<N*2;j+=2)
        {
            if(strcmp(slogan, str[j])==0)
            {
                puts(str[j+1]);
                break;
            }
        }
    }
    return 0;
}
