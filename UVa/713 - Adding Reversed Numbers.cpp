#include<bits/stdc++.h>
using namespace std;
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
//   reverse(str.begin(),str.end());
    return str;
}
int main()
{
    int TC;
    string s1,s2,s;
    cin >> TC;
    while(TC--)
    {
        cin >> s1 >> s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        s = sum(s1,s2);
        while(s[0] == '0')
        {
            s.erase(s.begin());
        }
        if(s.empty())
        {
            s.insert(s.begin(),'0');
        }
        cout << s << endl;
    }
}
