#include<bits/stdc++.h>
using namespace std;
int T[500][500][20];
int arr[500][500];
int main()
{
    int TC,idx=0;
    scanf("%d",&TC);
    while(TC--)
    {
        int n,q;
        scanf("%d %d",&n, &q);
        memset(T,0,sizeof(T));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&T[j][i][0]);
                arr[j][i] = T[j][i][0];
            }
        }
        int lim = floor(log2(n)) + 1;
        for(int k = 0; k<n; k++)
        {
            for(int i=1; i<lim; i++)
            {
                for(int j=0; j<n-(1<<i)+1 ; j++)
                {
                    int ind1 = j;
                    int ind2 = j + (1<<i-1);
                    T[k][j][i] = max(T[k][ind1][i-1], T[k][ind2][i-1]);
                }
            }
        }
        printf("Case %d:\n",++idx);
        while(q--)
        {
            int q1, q2, s;
            scanf("%d %d %d",&q1, &q2, &s);
            q1--;
            q2--;
            int st_x = q1, st_y = q2;
            int en_x = q1+s-1;
            int en_y = q2+s-1;
            int r = log2(en_x-st_x+1);
            int Max = 0;
//            printf("st_x = %d en_x = %d st_y = %d en_y= %d\n",st_x,en_x,st_y,en_y);
//            for(int i=st_y;i<=en_y; i++)
//            {
//                for(int j=st_x; j<= en_x; j++)
//                {
//                    printf("%d ",T[j][i][0]);
//                }
//                cout << endl;
//            }
            for(int i=st_y; i<=en_y; i++)
            {
                int v1 = T[i][st_x][r];
                int v2 = T[i][en_x-(1<<r)+1][r];
                int cur = max(v1,v2);
                Max = max(Max,cur);
            }
            printf("%d\n",Max);


        }
    }
}
