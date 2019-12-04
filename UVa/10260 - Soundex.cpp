#include<bits/stdc++.h>
using namespace std;

int check(char c)
{
    if(c == 'B' || c == 'F' || c =='P' || c == 'V'){ return 1;}
    else if(c == 'C' || c == 'G' || c =='J' || c == 'K' || c =='Q' || c == 'S' || c == 'X' || c =='Z'){ return 2;}
    else if(c == 'D' || c == 'T' ){ return 3;}
    else if(c == 'L'){ return 4;}
    else if(c == 'M' || c == 'N'){ return 5;}
    else if(c == 'R'){ return 6;}
    else { return 0;}
}
int main()
{
    char s[30],c;
    int n,i;
    while(scanf("%s",&s)==1)
    {
        int l = -1;
        int len = strlen(s);
        for(i=0;i<len;i++)
        {
            n = check(s[i]);
            if(n && n!=l){printf("%d",n);}
            l = n;
        }
        printf("\n");
    }
}
