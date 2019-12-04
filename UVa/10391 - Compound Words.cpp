#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str[120100],res[120100],c1,c2;
    int i = 0,j,k,x;
    while(getline(cin, str[i]))
    {
           i++;
    }
    i--;
    int m=0;
    for(j=i;j>=0;j--)
        {
            for(k=0;k<j;k++)
            {
                c1 = str[k] + str[j];
                c2 = str[j] + str[k];
                //cout << "c1 =" <<c1 <<" c2 =" << c2 << endl;
            for(x=i;x >= 0;x--){
            if(c1 == str[x])
            {
                res[m] = str[x];
                m++;
                //cout << str[x] << endl;
                break;
            }
            else if(c2 == str[x])
            {
                res[m] = str[x];
                m++;
                //cout << str[x] << endl;
                break;
            }
            }
            }
        }

    for(i=0 ; i < m-1; i++)
    {
        for(j=i+1; j < m; j++)
        {
            if(res[i]>res[j])
            {
                res[i].swap (res[j]);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        cout << res[i] <<endl;
    }
}
