#include<bits/stdc++.h>
using namespace std;
#define limit 1000000
long long int num[limit];
dreamliner()
{
    long long int a,b,c,d,e,f;
    for(a=4;a<limit;a+=2)
    {
        num[a]=1;
    }
    for(b=3;b<limit;b+=2)
    {
        d=2;
        for(c=b*d;c<=limit;c=b*d)
        {
            num[c]=1;
            d++;
        }
    }
}

int main()
{
    long long int x,y,z,sum,value;
    char word[1000];
    dreamliner();
    while(gets(word))
    {
        y=strlen(word);
        sum=0;value=0;z=0;
        for(x=0;x<y;x++)
        {
            z=word[x];
            if(word[x]>='A' && word[x]>='Z') value=-38+z;
            if(word[x]>='a' && word[x]>='z') value=-96+z;
            sum=sum+value;
        }
        if(num[sum]==0) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
