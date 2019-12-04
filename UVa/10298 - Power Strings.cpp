#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,len,a[99999],x,test,k,cnt,Lenth;
    string sub,sub1,str;
    while(getline(cin, str))
    {
        if(str == ".")
        {
            break;
        }
        cnt =0;
        len = str.length();
        //cout << len;
        x = -1;
        memset(a,0,sizeof(a));
        for(i=0; i<len; i++)
        {
            test = 0;
            k = i;
            for(j=i+1; j<len; j++)
            {
                if(str[i]==str[j])
                {
                    if(test ==0)
                    {
                        x++;
                        test++;
                        Lenth = j - k;
                    }
                    sub = str.substr(i,Lenth);
                    //   cout << "j-k = " << j-k <<" len-j = " << len-j << " X = " <<x <<endl;
                    // cout << "i = " << i <<" j = " << j << "test = " <<test <<endl <<endl;
                    if((j-k) <= (len - j))
                    {
                        sub1 = str.substr(j,Lenth);
                        /*cout <<"X =" << x <<" sub =" << sub <<"  sub1 ="<< sub1 << endl;
                        cout <<"k =" << k <<" j-k =" << j-k <<"  j ="<< j << endl;*/
                        if(sub==sub1)
                        {
                            a[x]++;
                        }
                    }
                }
                if(test > 0)
                {
                    k = j;
                }
            }
        }
        for(i=0; i<=x+1; i++)
        {
            //  cout << a[i] << endl;
            if(cnt < a[i])
            {
                cnt = a[i];
            }
        }
        cout << cnt + 1 << endl;
    }
}
