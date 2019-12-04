#include<bits/stdc++.h>
using namespace std;

int check (int dif)
{
    if(dif >= 10000) return 10000;
    if(dif >= 1000) return 1000;
    if(dif >= 100) return 100;
    if(dif >= 10) return 10;
    if(dif >= 1) return 1;
    return 0;
}

int main()
{
    int success,B, Team[100], Round_num,Player,dai,dif,i;
    int sum_dai, sum_player,dai_total;
    while(scanf("%d %d",&Player,&Round_num)==2){
    sum_dai = 0;
    dai_total = 0;
    while(Round_num--)
    {
        sum_player = 0;
        scanf("%d",&B);
        scanf("%d",&dai);

        for(i = 0;i < Player-1; i++)
        {
            scanf("%d",&Team[i]);
            sum_player += Team[i];
        }
        sum_player += dai;
        if(B >= sum_player)
        {
            dai_total += dai;
            dif = B - sum_player + dai;
            sum_dai += check (dif);
            //cout <<"check dif =" <<check(dif) <<endl;
        }
        else
        {
            while(dai!=0)
            {
                dif = dai - dai/10;
                sum_player -= dif;
                dai = dai/10;
                if(B >= sum_player)
                {
                    break;
                }
            }
            //cout << "Dai =" << dai <<endl;
            sum_dai += dai;
        }
        //cout <<"sum_dai =" <<sum_dai <<endl;
        //cout <<"dai_total =" <<dai_total <<endl;
    }
    cout << sum_dai-dai_total <<endl;
    }
}
