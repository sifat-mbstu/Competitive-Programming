#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TC,i,j,bar,Ball,x;
    char str[10][10],c;
    scanf("%d",&TC);
    c = getchar();
    for(x = 1; x<= TC; x++){
    Ball = 2;
    bar = 0;
    for(i=0;i<5;i++)
    {
        scanf("%s",str[i]);
        //puts(str[i]);
    }
    for(i=0;i<5;i++)
    {
        if(str[0][i] == '|'){bar = i; break;}
    }
    //cout << bar <<endl;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(str[i][j] == '>' || str[i][j] == '<')
            {
                if(str[i][j] == '>')
                {
                    //cout <<"i =" <<i <<" j=" <<j <<endl;
                    if(j>bar){ Ball = 0;}
                    else if(j<bar){ Ball = 1;}
                    break;
                }
                else if(str[i][j] == '<')
                {
                    //cout <<"i =" <<i <<" j=" <<j <<endl;
                    if(j>bar){ Ball = 1;}
                    else if(j<bar){ Ball = 0;}
                    break;
                }
            }
        }
        if(Ball < 2) break;
    }
    //c = getchar();
    if(Ball) {printf("Case %d: Thik Ball\n",x);}
    else {printf("Case %d: No Ball\n",x);}
    //if(TC!=x){printf("\n");}
    }
    return 0;
}
