#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara_1[120], ara_2[120], i,len,TC;
    char str[10][10] = {{' '}, {'.',',','?','"'},{'a','b','c'},{'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'},
     {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'} };
    scanf("%d",&TC);
    while(TC--){
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%d", & ara_1[i]);
    }
    for(i=0; i<len; i++)
    {
        scanf("%d", & ara_2[i]);
    }
    for(i=0; i<len; i++)
    {
        printf("%c", str[ara_1[i]][ara_2[i]-1]);
    }
    printf("\n");
    }
}
