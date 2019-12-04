#include<bits/stdc++.h>
using namespace std;
int main()
{
    double X, Y, dif;
    int ans;
    while(scanf("%lf %lf",&X, &Y)==2){
        dif = Y - X;
        dif = X / dif;
        ans = ceil(dif);
        printf("%d\n",ans+1);
    }
}
