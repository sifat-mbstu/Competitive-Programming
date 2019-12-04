#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
stack<pii>st;
pii arr[100];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=0; i<n; i++)
    {
        char s[10];
        ll a,b;
        scanf("%s %lld %lld",&s, &a, &b);
        ll v = s[0]-'A';
        arr[v] = pii(a,b);
    }
    string ss;
    ll lo=0,hi=0;
    ll res=0;

    while(getline(cin,ss))
    {
    res=0;
        while(!st.empty()) st.pop();
        if(ss.size()==0) continue;
        for(ll i=0; i<ss.size(); i++)
        {
            if(ss[i]=='(') lo++;
            else if(ss[i]==')')
            {
                lo--;
                ll a2 = st.top().first;
                ll b2 = st.top().second;
                st.pop();
                ll a1 = st.top().first;
                ll b1 = st.top().second;
                st.pop();
//                printf("=> %lld %lld %lld %lld\n",a1,b1, a2, b2);
                if(b1!=a2){res=-1;break;}
                res += (a1*b1*b2);

                st.push(pii(a1,b2));
            }
            else
            {
                ll v = ss[i]-'A';
//                cout << arr[v].first << endl;
//                cout << arr[v].second << endl;
                st.push(arr[v]);
            }
        }
        if(res==-1) printf("error\n");
        else printf("%lld\n",res);
    }
}
