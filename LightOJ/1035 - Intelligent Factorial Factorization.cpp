#include "bits/stdc++.h"
using namespace std;
#define MAXN   105
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int arr[150];
vector<int>Map[120];
int main()
{
    sieve();
    for(int i=2; i<=100; i++)
    {
        vector<int> now = getFactorization(i);
        for(int j=0; j<now.size(); j++)
        {
            int u = now[j];
            arr[u]++;
        }
        now.clear();
        for(int j=2; j<=100; j++)
        {
            if(arr[j]>0)
            {
                Map[i].push_back(j);
                Map[i].push_back(arr[j]);
            }
        }
    }

    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d = ",++idx,n);
        for(int i=0; i<Map[n].size(); i+=2)
        {
            int a1 = Map[n][i];
            int a2 = Map[n][i+1];
            if(i==0) printf("%d (%d)",a1,a2);
            else
            {
                printf(" * %d (%d)",a1,a2);
            }
        }
        printf("\n");
    }
}
