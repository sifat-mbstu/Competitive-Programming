#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    multiset <ll> Set;
    multiset <ll> :: iterator it2,it1;
    ll n,k,num,sum,dif;
    while(scanf("%lld",&n) == 1)
    {
        sum = 0;
        if(n==0) break;
        Set.clear();
        while(n--)
        {

            scanf("%lld",&k);
            while(k--)
            {
                scanf("%lld",&num);
                // cout << num << endl;
                Set.insert(num);
            }
            it1 = Set.begin();
            it2 = Set.end();
            --it2;
            dif = (*it2) - (*it1);
            sum += dif;
            //cout << (*it2) << endl;
            Set.erase(it1);
            Set.erase(it2);
        }
        printf("%lld\n",sum);
    }
}
