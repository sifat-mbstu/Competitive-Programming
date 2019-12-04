#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);

struct Dic{
    string s[200];
} book[1000100],temp;

int main()
{
    FI;
    set <string> myset;
    set <string>:: iterator it;
    int i = 0,j = 0,k;
    bool t = 0;
    char c;
    while(scanf("%c",&c)==1)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(c < 97){c += 32;}
            t =1;
            book[i].s.push_back(c);
            j++;
        }
        else
        {
            //book[i].s[j] = '\0';
            myset.insert(book[i].s[j]);
            if(t) {i++; t = 0;}
            j = 0;
        }
    }
    //str_sort(i);
    for(k = 0; k < i; k++)
    {
        if(k > 0){j = k-1;
        //while(strcmp(book[j].s,book[k].s)==0) k++;}
        for(it = myset.begin(); it != myset.end(); it++)
            cout << *it <<endl;
            //printf("%s\n",book[k].s);
        cout <<
    }
}
