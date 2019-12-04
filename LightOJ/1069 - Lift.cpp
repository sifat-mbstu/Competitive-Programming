#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind=0;
    cin >> TC;
    while(TC--){
    int a, b;
    scanf("%d%d",&a,&b);
    int dif = abs(a-b);
    printf("Case %d: %d\n",++ind,((dif+a)*4)+19);
}
}
