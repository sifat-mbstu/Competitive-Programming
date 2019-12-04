///Accepted
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,cases,k,T;
    char teams[100],judge[100],c,test_team[100],test_judge[100];
    scanf("%d",&cases);
    c = getchar();
    for(T=1; T <= cases; T++)
    {
        gets(teams);
        gets(judge);
        int team_len= strlen(teams);
        int judge_len= strlen(judge);
        if(strcmp(teams, judge)==0)
        {
            printf("Case %d: Yes\n",T);
        }
        else
        {
            k=0;
            for(i=0; i<team_len; i++)
            {
                if(teams[i] != ' ')
                {
                    test_team[k] = teams[i];
                    k++;
                }
            }
            test_team[k] = '\0';
            k=0;
            for(i=0; i<judge_len; i++)
            {
                if(judge[i] != ' ')
                {
                    test_judge[k] = judge[i];
                    k++;
                }
            }
            test_judge[k] = '\0';

            if(strcmp(test_judge,test_team)==0)
            {
                printf("Case %d: Output Format Error\n",T);
            }
            else
            {
                printf("Case %d: Wrong Answer\n",T);
            }
        }
    }
    return 0;
}
