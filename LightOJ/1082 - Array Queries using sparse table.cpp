
#include<bits/stdc++.h>
using namespace std;
int T[100005][20],ara[100005];
int find_min(int a, int b, int N)
{
    int l=b-a+1;
    int k = floor(log2(l));
    int ind1 = T[a][k];
    int ind2 = T[b+1-(1<<k)][k];
    return min(ara[ind1],ara[ind2]);
}

int main()
{
    int TC,t=0;
    cin >> TC;
    while(TC--){
    memset(T, 0, sizeof(T));
    int N, q;
    cin >> N >> q;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&ara[i]);
        T[i][0] = i;
    }
    int col = floor(log2(N)) + 1;

    for(int j=1; j<col; j++)
    {
        for(int i=0; i<N + 1 - (1<<j); i++)
        {
            if(ara[T[i][j-1]] <= ara[T[i+(1<<j-1)][j-1]]) {T[i][j] = T[i][j-1];}
            else {T[i][j] = T[i+(1<<j-1)][j-1];}
        }
    }
    int a,b;
    printf("Case %d:\n",++t);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",find_min(a-1,b-1,N));
    }
    }
}
