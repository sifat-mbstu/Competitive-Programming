#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,TC,N,B,K,a,i,j,rem,sum,res;
    scanf("%d",&TC);
    while(TC--){
    scanf("%d %d",&N,&B);
    sum = res = 0;
    rem = 1;
    for(i=0;i<B;i++)
    {
        scanf("%d",&K);
        rem = 1;
        for(j=0;j<K;j++)
        {
            scanf("%d",&a);
            a *= rem;
            //cout <<"a =" <<a << endl;
            rem = a % N;
            //cout <<"Rem =" << rem <<endl;
        }
        res = (rem + res) % N;
           // cout <<"Res =" << res <<endl;
    }
    printf("%d\n",res);
    }
}
