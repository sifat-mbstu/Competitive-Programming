#include<bits/stdc++.h>
using namespace std;
#define FI freopen ("input.txt", "r", stdin);
#define FO freopen ("output.txt", "w", stdout);
bool check_limit(string s)
{
    string lim = "2147483647";
    int len1 = s.size();
    int len2 = lim.size();
    if(len1 > len2){return 0;}
    else if(len2 > len1) {return 1;}
    else{
    if(s <= lim) {return 1;}
    else {return 0;}
    }
}

bool sum(string s1, string s2)
{
    int dif,len,carry,i,res;
    string str;fthuh
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
    //cout << s1 <<" " <<s2 << endl;
    len = s1.size();
    int j = 0;
    carry = 0;
    for(i = len-1; i >= 0; i--)
    {
        int num1 = s1[i] - '0';
        int num2 = s2[i] - '0';
        int sum = num1 + num2;
        int digit = floor(log10(sum)) + 1;
        if(digit==1)
        {
            res = sum + carry + '0';
            carry = 0;
            str.push_back(res);
        }
        else
        {
            res = (sum%10) + carry+ '0';
            carry = sum / 10;
            str.push_back(res);
        }
    }
    if(carry != 0) {
    res = carry + '0';
    str.push_back(res);
    }
    //cout << str;
    reverse(str.begin(), str.end());
    return check_limit(str);
}
/*
bool product(string s1, string s2)
{
int i, digit, multi, len1, len2, j, carry, a, b, x, Max, k;
    string s3[1000],str;
    string::iterator it;
    cin >> s1 >> s2;
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
    return check_limit(str);
}
*/
bool product(string s1, string s2)
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
    return check_limit(str);
}
int main()
{
    FO;
    int t1,t2,res;
    string str1,str2,sign;

    while(cin >> str1 >> sign >> str2)
    {
        t1 = check_limit(str1) ;
        t2 = check_limit(str2);
        if(t1 == 0 || t2 == 0) { res = 0; }
        else
        {
            if(sign == "*")
            {
                res = product(str1,str2);
            }
            else
            {
                res = sum(str1,str2);
            }
        }
        cout << str1 << " " << sign << " " << str2;

        if(t1 && t2 && res) {cout << " \\\\" << endl;}
        else {cout << endl;}

        if(!t1) cout << "first number too big" <<endl;
        if(!t2) cout << "second number too big" <<endl;
        if(!res) cout << "result too big" <<endl;
    }
}
