#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt", "w", stdout);
    int N, H, Ta, Tb, i, TC,x,cnt,a[100001];
    scanf("%d",&TC);
    for(x=1; x<=TC; x++){
    cnt = 0;
    scanf("%d %d %d %d",&N, &H, &Ta, &Tb);
    //printf("%d %d %d %d\n\n",N, H, Ta, Tb);
    for(i=0; i<N; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a, a+N);
    /*for(i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }*/
    if(Tb <(Ta*2) && ((a[0] + a[1]) < H))
    {
        int j = 0; i = N-1;
            //cout << "Hmmm..\n";
            while(1)
            {
                if(j>=i) break;
                if((a[i] + a[j]) < H)
                {
                    cnt++;
                    i--; j++;
                    //printf("cnt == %d\n",cnt);
                }
                else{i--;}
            }
        cnt = (cnt * Tb) + (N - (cnt*2))*Ta;
    }
    else{
        cnt = N * Ta;
    }
    printf("Case %d: %d\n",x,cnt);
    }
}
