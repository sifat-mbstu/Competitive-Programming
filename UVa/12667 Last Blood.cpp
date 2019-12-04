#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t,m,i,j,num,test;
    long long time[1100], team[200], Prob[100][1010], Final[20],k;
    char verdict[1100][10],c,Pr;
    while(scanf("%lld %lld %lld",&n,&t,&m)==3)
    {
    for(i=0; i<18; i++)
    {
        for(j=0; j<1001; j++)
        {
            Prob[i][j] = -1;
        }
    }
    for(i=0; i<n; i++)
    {
        Final[i] = -1;
    }
    for(i=0; i<m; i++)
    {
        j = test =0;
        scanf("%lld %lld %c  %s", &time[i], &team[i],&Pr,  verdict[i]);

        num = Pr - 65;

        while(Prob[num][j] !=-1)
        {
            j++;
        }
        if(strcmp(verdict[i], "Yes")==0)
        {
            Prob[num][j] = i;
            for(k=j-1; k>=0; k--)
            {

                if(team[i] != team[Prob[num][k]])
                {
                    test = 0;
                }
                else
                {
                    test = 1;
                    break;
                }
            }

            if(test == 0 || j==0)
            {
                Final[num] = Prob[num][j];
            }
        }
    }

    for(i=0; i<n; i++)
    {

        if(Final[i]> -1)
        {
            printf("%c",i+65);
            cout <<' ' << time[Final[i]] << ' '<< team[Final[i]] << endl;
        }
        else
        {
            printf("%c - -\n",i+65);
        }
    }
    }
}
