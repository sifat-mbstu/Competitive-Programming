#include<bits/stdc++.h>
using namespace std;
struct Fib{
    string s;
}fib[5010];

string sum(string s1, string s2)
{
    int dif,len,carry,i,res,n;
    string str;
    int len1, len2;
    len1 = s1.size();
    len2 = s2.size();
    if(len1 > len2)
    {
        dif = len1 - len2;
        while(dif--)
        {
            s2.insert(s2.begin(), '0');
        }
    }
    else if(len2 > len1)
    {
        dif = len2 - len1;
        while(dif--)
        {
            s1.insert(s1.begin(), '0');
        }
    }
    len = s1.size();
    int j = 0;
    carry = 0;
    for(i = len-1; i >= 0; i--)
    {
        int num1 = s1[i] - '0';
        int num2 = s2[i] - '0';
        int sum = num1 + num2 + carry;
        n = sum % 10;
        str.push_back(n + '0');
        carry = sum / 10;
    }
    while(carry !=0)
    {
        n = carry % 10;
        str.push_back(n+'0');
        carry /= 10;
    }
   reverse(str.begin(),str.end());
    return str;
}

int main()
{
    int i,n;
    fib[0].s = "0";
    fib[1].s = "1";
    for(i=2; i<5002; i++)
    {
        fib[i].s = sum(fib[i-1].s,fib[i-2].s);
    }
    while(cin >> n)
    {
        cout << "The Fibonacci number for "<< n << " is " <<fib[n].s << endl;;
    }
}
