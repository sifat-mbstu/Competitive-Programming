//Time Limit Obviously
#include<bits/stdc++.h>
using namespace std;
string Rev( string str)
{
    string REV;
   int len = str.size();
   for(int i=0; i <len ; i++)
   {
       REV.push_back(str[i]);
   }
   return REV;
}
string product(string s1, string s2)
{
    /*str.clear();
    for(i=0;i<1000;i++) s3[i].clear();*/
    int i, digit, multi, len1, len2, j, carry, a, b, x, Max, k;
    string s3[10000],str;
    string::iterator it;
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
    return str;

}

int main()
{
    int i,fact,num;
    string multi_str, i_str;
    while(cin >> fact){
    multi_str.clear();
    multi_str.push_back('1');
    i_str.clear();
    for(i=1;i<=fact;i++)
    {
        num = i;
        while(num != 0)
        {
            i_str.insert(0, 1 ,num%10 + '0');
            num /= 10;
        }
        multi_str = product(multi_str,i_str);
       // cout <<"multi = " <<multi_str << endl;
        //cout << "i = " << i_str << endl;

        i_str.clear();
    }
    cout << multi_str << endl;
    }
}
