    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    multiset<ll>Set;
    multiset<ll> :: iterator it;
    int main()
    {
        ll idx = 0,n;
        Set.clear();
        while(scanf("%lld",&n)==1)
        {
            Set.insert(n);
            idx++;
            if(idx%2)
            {
                ll mid = idx/2;
                it = Set.begin();
                while(mid--)it++;
                ll v = *it;
                printf("%lld\n",v);
            }
            else
            {
                ll mid = idx/2-1;
                ll v1, v2;
                it = Set.begin();
                while(mid--)it++;
                v1 = *it;
                it++;
                v2 = *it;
                ll v = (v1 + v2) / 2;
                printf("%lld\n",v);
            }

        }
    }
