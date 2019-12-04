#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005] = {0};
ll b[1000005] = {0};
int main()
{
    vector <ll> vec;
    ll n,i,num,num1;
    i = 0;
    while(scanf("%lld",&num)==1){
        if(num>=0){
        if(a[num] == 0) {vec.push_back(num);}
        a[num]++;
        }
        else if (num < 0)
        {
            num1 = num * (-1) ;
            if(b[num1] == 0){ vec.push_back(num);}
            b[num1]++;
        }
        i++;
    }
    for(i=0;i<vec.size();i++)
    {
        if(vec[i] >= 0){
        printf("%lld %lld\n",vec[i],a[vec[i]]);
        }
        else if(vec[i] < 0)
        {
            printf("%lld %lld\n",vec[i],b[(-1)*vec[i]]);
        }
    }
}
