#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);
#define ll long long int
int main()
{
    //FI;FO;
    ll i,j,k,sum,a,n,TC=0,pos[100],neg[100];
    while(cin >> n){
    sum = 1;
    bool t = 0;
    j = 0;
    k = 0;
    for(i=1;i<=n;i++)
    {
        cin >> a;
        if(a != 0)
        {
            sum *= a;
            printf("sum = %lld\n",sum);
            if(sum > 0){ pos[j] = sum;j++;t = 1;}
            if(sum < 0){}
        }
        else
        {
            sum = 1;
        }
    }
    printf("j = %lld\n\n",j);
    for(i=0;i<j;i++)
    {
        printf("ara = %lld\n",pos[i]);
    }
    sort(pos,pos+j);
    sum = pos[j-1];
    if(t == 0){printf("Case #%lld: The maximum product is 0.\n\n",++TC);}
    else{printf("Case #%lld: The maximum product is %lld.\n\n",++TC,sum);}
}
}
