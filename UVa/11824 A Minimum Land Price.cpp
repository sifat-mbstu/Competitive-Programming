#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll ara[100], N, i, j,k, sum, TC;
    double num;
    cin >> TC;
    while(TC--){
    i = 0;
    N = 1;
    while(N!=0)
    {
        scanf("%lld",&N);
        ara[i++] = N;
    }
    sum = 0;
    k=0;
    sort(ara, ara+i-1);
    for(j=i-2; j >= 0; j--)
    {
        num = (double) pow((double)ara[j], k+1);
        //printf("Num = %lf\n", num);
        num *= 2;
        sum += num;
        k++;
        if(sum > 5000000){break;}
    }

        if(sum <= 5000000) cout << sum << endl;
        else printf("Too expensive\n");
    }
    return 0;
}
