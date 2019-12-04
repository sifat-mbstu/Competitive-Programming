#include<bits/stdc++.h>
using namespace std;
#define MAX 1020
vector <int> ara [MAX];
vector <int> counts [MAX];

int main()
{
    char str[1050];
    int i,j,len,num;
    gets(str);
    //while(gets(str))
    //{
    len = strlen(str);
    puts(str);
    for(i=0; i < len; i++)
    {
        ara[str[i]].push_back(i);
    }



    for(i=0;i<260;i++)
    {
        if(ara[i].size()>0)
        {
            num = ara[i].size();
            counts[num].push_back(num);
        }
    }
    for(i=1;i<1010;i++)
    {
        if(counts[i].size() > 0)
        {
            for(j = 1000; j >=0; j--)
            {
                if(ara)
            }
        }
    }
    /*
    for(i=1;i<1010;i++)
    {
        while(counts[i] > 0 && counts[i] <= 1000)
            {
                for(j=1000;j >= 0 ; j--)
                {
                    if(ara[j] == i)
                    {
                        printf("%d %d\n",j, ara[j]);
                        ara[j] = 0;
                    }
                    counts[i]--;
                }
            }
    }
    printf("\n");
    }*/
}
