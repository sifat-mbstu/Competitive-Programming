#include<bits/stdc++.h>
using namespace std;
int main()
{
    int TC, ind =0;
    scanf("%d",&TC);
    while(TC--){
    int n1, n2,sum = 0;
    scanf("%d",&n1);
    for(int i=0; i<n1; i++)
    {
        scanf("%d",&n2);
        if(n2<0)n2=0;
        sum += n2;
    }
    printf("Case %d: %d\n",++ind,sum);
    }
}
