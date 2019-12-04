#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            int A[10][10];
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<2;k++)
                {
                    cin>>A[j][k];
                }
            }
            int flag=0;

            if((A[2][0]==A[0][0])&&(A[2][1]==A[0][1]))
            {
                if((A[3][0]==A[1][0])&&(A[3][1]==A[1][1]))
                {

                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
            else if((A[2][0]==A[1][1])&&(A[2][1]==A[1][0]))
            {
                if((A[3][0]==A[0][1])&&(A[3][1]==A[0][0]))
                {

                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
            else if((A[2][0]==A[0][1])&&(A[2][1]==A[1][1]))
            {
                if((A[3][0]==A[0][0])&&(A[3][1]==A[1][0]))
                {

                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
            else if((A[2][0]==A[1][0])&&(A[2][1]==A[0][0]))
            {
                if((A[3][0]==A[1][1])&&(A[3][1]==A[0][1]))
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }


            if(flag==1)
            {
                printf("Case #%d: POSSIBLE\n",i);
            }
            else
            {
                printf("Case #%d: IMPOSSIBLE\n",i);
            }
        }
    }
    return 0;
}
