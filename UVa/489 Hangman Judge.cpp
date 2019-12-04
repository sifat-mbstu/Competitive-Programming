#include<bits/stdc++.h>
using namespace std;
int main()
{
    int given[400],guess[400],i,N;
    char c;
    while(scanf("%d",&N)==1)
    {
        c = getchar();
        if(N==-1){break;}
        memset(given,0,sizeof(given));
        for(i=0; ; i++)
        {
            scanf("%c",&c);
            //cout << c <<endl;
            if(c=='\n') break;
            given[c] = 1;
        }
        int strike = 0;
        for(i=0; ; i++)
        {
            scanf("%c",&c);
            if(c=='\n') break;
            if(given[c] != 1)
            {
                strike++;
            }
            else
            {
                given[c] = 0;
            }
        }
        int win = 1;
        cout <<"Round " << N<<endl;
        if(strike >= 7)
        {
            printf("You lose.\n");
        }
        else
        {
            for(i=0; i<300 ; i++)
            {
                if(given[i] == 1)
                {
                    win = 0;
                }
            }
            if(win)
            {
                printf("You win.\n");
            }
            else
            {
                printf("You chickened out.\n");
            }
        }
    }
}
