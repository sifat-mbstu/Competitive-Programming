#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int toInt (string str){
    stringstream ss;
    ss<<str;
    int a ;
    ss>>a;
    return a;

}

string toString (int n){
    stringstream ss;
    ss<<n;
    string str;
    ss>>str;
    return str;

}



int main()
{
    //int a = toInt("123");
    //string str = toString(a);
    //cout << str << endl;

    //FO;
    ll fin,n,a[100], num, multi, j, sum,dif;
    while(cin >> n){
    num = n;
    ll i = 0;
    while(num!=0)
    {
        a[i++] = num % 10;
        num /= 10;
    }
    sort(a,a+i);
    ll Max = 0 ;
    do
    {
        sum = 0;
        multi = 1;
        for(j = 0; j<i; j++)
        {
            sum += a[j] * multi;
            multi *= 10;
        }
        //cout << sum << endl;
        ll l1 = floor(log10(n)) + 1;
        ll l2 = floor(log10(sum)) + 1;
        if(l1 == l2)
        {
            dif = abs(sum - n);
            //cout << "dif =" << dif << endl;
            if(dif % 9==0)
            {
                if(Max <dif)
                {
                    fin = sum;
                    //cout << fin << endl;
                    Max = dif;
                }
            }
        }
    }
    while(next_permutation(a,a+i));
    ll nine = 9;
    ll res = Max/9;
    if(n > fin) swap(n,fin);
    printf("%llu - %llu = %llu = %llu * %llu\n",fin, n, Max, nine, res);
    }
}
