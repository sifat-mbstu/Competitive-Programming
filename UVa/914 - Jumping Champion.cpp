#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
#define ll long long
vector<ll>prime;
bool a[mx];
bool b[mx];

struct Divi
{
    ll val;
    ll ind;
} S[mx];

bool sorter(Divi const& N1, Divi const& N2)
{
    if(N1.val > N2.val)
    {
        return 1;
    }
    return 0;

}
void sieve()
{
    a[1] = 1;
    prime.push_back(2);
    for(ll i=4; i<=mx; i+=2)
        a[i] = 1;
    for(ll i=3; i<=mx; i++)
    {
        if(a[i] == 0)
        {
            prime.push_back(i);
            for(ll j = i * i ; j<=mx; j+=i)
                a[j] = 1;
        }
    }
}

int main()
{
    sieve();
    ll TC;
    cin >> TC;
    while(TC--){
    ll n, frm, to;
    cin >> frm >> to;
    for(ll i=0; i<mx; i++)
        {S[i].val = S[i].ind = 0;}
    //Divi S[mx] = {0};
    for(ll i=0; i<prime.size()-1; i++)
    {
        ll n1 = prime[i];
        ll n2 = prime[i+1];
        if ((n1>=frm && n1<=to) && (n2>=frm && n2<=to))
        {
            ll dif = n2-n1;
            S[dif].ind = dif;
            S[dif].val++;
       //     printf("n1 = %lld n2 = %lld dif = %lld\n",n1,n2,dif);
        }
    }
    sort(S,S+to,&sorter);
    ll cnt = 0;
    for(ll i=0; i<3; i++)
    {
        if(S[i].val)
        {
            cnt++;
   //         cout << S[i].val << endl;
        }
    }
    if((S[0].val == S[1].val)) printf("No jumping champion\n");
    else printf("The jumping champion is %lld\n",S[0].ind);
    }
}
