#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len,i,j,k,n,N;
    string s;
    while(getline(cin,s)){
    len = s.size();
    n = 0;
    for(i=len-1;i>=0;i--)
    {
        //cout << n << endl;
        if(s[i] <= 'z' && s[i] >= 'p')
        {
            //0cout << s[i] <<endl;
            n++;
        }
        else if(s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I')
        {
            if(n>=2)
            {
                n--;
            }
            else
            {
                n = 0;
                break;
            }
        }
        else if(s[i] == 'N')
        {
            if(n<1)
            {
                n=0;
                break;
            }
        }
        //cout << n << endl;
    }
    if(n==1){ cout << "YES" << endl;}
    else{ cout << "NO" <<endl;}
    }
}
