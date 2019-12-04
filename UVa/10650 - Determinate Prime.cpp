#include<bits/stdc++.h>
using namespace std;
#define mx 33000
#define ll long long
vector<ll>prime;
bool a[mx];
ll s[mx];
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
            for(ll j = i*i ; j<=mx; j+=i)
                a[j] = 1;
        }
    }
}
int main()
{
    sieve();
    ll dif1,dif = prime[1] - prime[0];
    for(ll i=2; prime[i] < 32000; i++)
    {
        dif1 = prime[i] - prime[i-1];
        if(dif1==dif) s[i] = s[i-1]+1;
        dif = dif1;
    }
    /*for(ll i=0; i<100; i++)
    {
        printf("i = %lld ... s[i] = %lld\n",i,s[i]);
        cout << "prime[i] = " << prime[i] << endl<< endl;
    }*/
    ll frm, to;
   while( cin >> frm >> to){
        if(!frm && !to)break;
    if(to <frm) swap(to,frm);
    ll start, End;
    for(ll i=0; prime[i] <= to; i++)
    {
        if(s[i]==1)
        {
            start = i-2;
            while(s[i]!=0) i++;
            End = --i;
//        cout << "frm =" << frm << " start = " << start << " prime = " << prime[start] << endl;
        if((frm <= prime[start] && prime[start] <= to) && (frm <= prime[End] && prime[End] <= to))
        {
            cout << prime[start];
            for(ll k=start+1; k<=End; k++)
                cout << " "<<prime[k];
            cout << endl;
        }
        }
    }
   }
}
