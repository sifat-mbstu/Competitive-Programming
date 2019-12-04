#include<bits/stdc++.h>
using namespace std;
set <int> Set;
set <int> :: iterator it;
int P,L;
void divi(int n)
{
    int sq = sqrt(n);
    for(int i=1; i<=sq; i++)
    {
        if(n%i==0)
        {
            int a1 = i;
            int a2 = n/i;
            if(a1>L)
                Set.insert(a1);
            if(a2>L)
                Set.insert(a2);
        }
    }
}
int main()
{
    int tc,idx=0;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&P, &L);
        Set.clear();
        int need = P-L;
        divi(need);
        printf("Case %d:",++idx);
        if(Set.size()>0)
        {
            for(it = Set.begin(); it!=Set.end(); it++)
            {
                int val = *it;
                printf(" %d",val);
            }
            printf("\n");
        }
        else
        {
            printf(" impossible\n");

        }
    }
}
