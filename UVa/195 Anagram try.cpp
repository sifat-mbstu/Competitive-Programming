///Accepted
#include<bits/stdc++.h>
using namespace std;
char in[1000];
//int cmp(const void *a, const void*b) { return *(char*)a-*(char*)b; }
bool comp(const char &a, const char &b)
{
    int delta = tolower(a) - tolower(b);
    if(delta) return (delta < 0);
    else return a < b;
    //return 0;
    //return delta?delta<0:a<b;
}
int main()
{
    int test, len;
    scanf("%d",&test);
    getchar();
    while (test--)
    {
        gets(in);
        len = strlen(in);
        sort(in,in+len,comp);
        do{cout << in << endl;}
        while (next_permutation(in,in+len,comp));
    }
    return 0;
}
