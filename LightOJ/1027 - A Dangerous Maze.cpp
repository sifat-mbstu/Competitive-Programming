#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC,tc=0;
    cin >> TC;
    while(TC--){
    int n;
    scanf("%d",&n);
    int sum=0,cnt=0;
    for(int i=0; i<n; i++)
    {
        int v;
        scanf("%d",&v);
        sum += abs(v);
        if(v>0) cnt++;
    }
    int ggcd = __gcd(sum,cnt);
    sum = sum/ggcd;
    cnt = cnt/ggcd;
    if(cnt>0)printf("Case %d: %d/%d\n",++tc,sum,cnt);
    else printf("Case %d: inf\n",++tc);
    }
}
