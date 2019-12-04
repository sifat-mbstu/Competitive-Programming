#include<bits/stdc++.h>
using namespace std;

struct country
{
    char str[200],tmp[100];
    int num_country;
}cntr[2010],temp,clr;
int main()
{
    //freopen("i.txt","r", stdin);
    /*freopen("o.txt","w", stdout);*/
    int n,i,j;
    while(scanf("%d",&n)==1){
    for(i=0;i<n;i++)
    {
        scanf("%s",&cntr[i].str);
        gets(cntr[i].tmp);
        cntr[i].num_country = 0 ;
        cntr[i].num_country++;

        for(j=i-1; j >= 0; j--)
        {
            if(strcmp(cntr[j].str,cntr[i].str)==0)
            {
                //cout << "j =" << j <<endl ;
                cntr[j].num_country++;
                i--;
                n--;
                break;
            }
        }
    }
    for(i=0 ; i < n-1; i++)
    {
        for(j=i+1; j < n; j++)
        {
            if(strcmp(cntr[i].str,cntr[j].str)> 0)
            {
                temp = cntr[i];
                cntr[i] = cntr[j];
                cntr[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout << cntr[i].str << " "<< cntr[i].num_country << endl;
    }
    for(i=0;i<n+1;i++)
    {
        cntr[i].num_country = 0;
    }
    }
}
