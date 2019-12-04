#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);

struct Dic{
    char s[200];
} book[1000100],temp;

void str_sort(int n)
{
    int i,j;
    for(i=0 ; i < n-1; i++)
    {
        for(j=i+1; j < n; j++)
        {
            if(strcmp(book[i].s,book[j].s)> 0)
            {
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
}
int main()
{
    //FI;
    int i = 0,j = 0,k;
    bool t = 0;
    char c;
    while(scanf("%c",&c)==1)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(c < 97){c += 32;}
            t =1;
            book[i].s[j] = c;
            j++;
        }
        else
        {
            book[i].s[j] = '\0';
            if(t) {i++; t = 0;}
            j = 0;
        }
    }
    str_sort(i);
    for(k = 0; k < i; k++)
    {
        if(k > 0){j = k-1;
        while(strcmp(book[j].s,book[k].s)==0) k++;}
        printf("%s\n",book[k].s);
    }
}
