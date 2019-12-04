#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, digit, multi, len1, len2, j, carry, a, b, x, Max, k;
    string s1,s2,s3[1000],str;
    string::iterator it;
    while(cin >> s1 >> s2){
    len1 = s1.size();
    len2 = s2.size();
    j = carry = Max = 0;
    for(i=len1-1; i >= 0 ; i--)
    {
        a = s1[i] - '0';
        for(j = len2 - 1 ; j>= 0 ; j--)
        {
            multi = a * (s2[j] - '0') + carry;
            digit = floor(log10(multi)) + 1;
            if(digit > 1 && j != 0)
            {
                b = multi % 10;
                carry = (multi / 10);
            }
            else{carry = 0; b = multi;}
            if(b <= 9) {s3[i].insert(0,1,(b+'0'));}
            else{  s3[i].insert(0,1,((b%10) + '0'));
                    s3[i].insert(0,1, ((b/10) + '0'));
            }
        }
        x = len1-1-i;
        while(x--)
        {
            s3[i].push_back('0');
        }
        //cout << s3[i] << endl;
        if(Max < s3[i].size()) {Max = s3[i].size();}
    }
    for(i = 0; i < len1; i++)
    {
        k = Max - s3[i].size();
        //cout << k;
        while(k--)
        {
            s3[i].insert(0, 1 , '0');
        }
        //cout << s3[i] << endl;
    }
    carry = 0;
    for(j = Max-1; j >= 0; j--)
    {
        a = 0;
        for(i = len1 - 1; i >= 0; i--)
        {
            a += s3[i][j] - '0' ;
            //cout << "s3[i][j] = " << s3[i][j] << endl;
        }
        a += carry;
       // printf("a = %d\n",a);
        b = floor(log10(a)) + 1;
        if(j == 0){
                while(a != 0)
                {
                    str.insert(0,1,((a%10) + '0'));
                    a /=10 ;
                    //cout << a << endl;
                }
        }
        else
        {
              str.insert(0,1,((a%10) + '0'));
            carry = a / 10;
        }
        //cout << str << endl;
    }
    it = str.begin()+0;
    while(str[0] == '0'){str.erase(it);}
    if(str.empty()){str.push_back('0');}
    cout << str << endl;
    str.clear();
    for(i=0;i<1000;i++) s3[i].clear();
    }
}
