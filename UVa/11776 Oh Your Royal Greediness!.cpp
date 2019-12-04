#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    FI;
    int N,en,i,t,j,TC=0,cnt1,cnt2;
    int S[2000], E[2000];
    while(scanf("%d",&N)==1){
    if(N<0){break;}
    en = 0;
    for(i=0;i<N;i++)
    {
         scanf("%d %d", &S[i], &E[i]);
    }
    for(i=0;i<N;i++)
    {
        cnt1 = cnt2 = 0;
        for(j=0; j < N; j++)
        {
            if(E[i] >= S[j] && E[i] <= E[j])
            {
                cnt1++;
            }
            if(S[i] >= S[j] && S[i] <= E[j])
            {
                cnt2++;
            }
        }
        printf("i = %d cn1= %d cn2 = %d\n ",i,cnt2, cnt1);
        int en1 = max(cnt1,cnt2);
        if (en1 > en) en = en1;
    }
    if(N == 1){ en  = 1;}
    printf("Case %d: %d\n",++TC,en);
    }
}
