#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,num,TC ;
    double sum, M,deci;
    map <char, double> Map;
    string s;
    Map['C'] = 12.01;
    Map['H'] = 1.008;
    Map['O'] = 16.00;
    Map['N'] = 14.01;
    cin >> TC;
    while(TC--){
    cin >> s;
    sum = 0.0;
    int len = s.size();
    for(i=0; i<len; i++)
    {
        if(s[i]<= 'Z' || s[i] >= 'A'){
            M = Map[s[i]];
            if((i+1) < len && s[i+1]>= '0' && s[i+1] <= '9')
            {
                deci = 0;
                while(s[i+1]>= '0' && s[i+1] <= '9')
                {
                    num = s[i+1] - '0';
                    deci = deci*10 + num;
                    i++;
                }
            }
            else{deci = 1;}
            sum += M*(double)deci;
        }
    }
    printf("%.3lf\n",sum);
    }
}
