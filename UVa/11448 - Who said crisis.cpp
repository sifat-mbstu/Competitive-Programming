#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int k,len1,len2,i,a,b,j,ara[50000],res,TC;
    string s1,s2,temp;
    cin >> TC;
    while(TC--)
    {
        cin >> s1 >> s2;
        memset(ara,-1,sizeof(ara));
        k = 0;
        len1 = s1.size();
        len2 = s2.size();
        int MINUS = 0;
        if(s2>s1 && len2 == len1)
        {
            swap(s2,s1);
            MINUS = 1;
        }
        if(len1 < len2)
        {
            swap(s2,s1);
            swap(len2,len1);
            MINUS = 1;
        }
        int dif = len1 - len2;
        while(dif--)
        {
            s2.insert(0, "0");
        }
        //cout << "s1 =" <<s1 <<" s2 =" <<s2 <<endl;
        len2 = len1;
        for(i=len1-1,j=len2-1; i>=0, j>=0; i--,j--)
        {
            a = s1[i] - '0';
            b = s2[j] - '0';
            res = a - b;
            //cout <<"res =" <<res <<endl;
            if((a-b) < 0)
            {
                s2[j-1]++;
                res += 10;
                ara[k] = res;
                k++;
            }
            else if((a-b) >= 0)
            {
                ara[k] = res;
                k++;
            }
        }

        if(MINUS)
        {
            cout << "-";
        }

        while(ara[k-1] == 0)
        {
            k--;
        }

        if(k<0)
        {
            k=1;
        }
        for(i=k-1; i>=0; i--)
        {
            cout <<ara[i] ;
        }
        cout << endl;
    }
}
