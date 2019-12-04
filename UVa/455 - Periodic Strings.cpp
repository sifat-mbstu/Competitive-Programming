#include<bits/stdc++.h>
using namespace std;
string p,text;
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

int temp[1000100];

int make_temp()
{
    int Min = p.size();
    memset(temp, 0, sizeof(temp));
    int j=0;
    int i=1;
    temp[0] = 0;
    for(i=1; i<p.size(); i++)
    {
        if(p[i]==p[j])
        {
            temp[i] = ++j;
            if(i==p.size()-1)
            {
                int lim;
                if(p.size() % 2){lim = (p.size()/2) + 1;}
                else {lim = p.size()/2;}
                if(j>=lim &&  p.size()%(Min-j)==0) Min = Min-j;
            }
        }
        else
        {
            while(j>0)
            {
                j = temp[j-1];
                if(p[i]==p[j])
                {
                    temp[i] = ++j;
                    break;
                }
            }
        }
    }
    return Min;
}

int main()
{
    int n,TC;
    bool flag = 0;
    cin >> TC;
    while(TC--)
    {
        if(flag)printf("\n");
        cin >> p;
        cout << make_temp() << endl;
//        printf("\n");
        flag = 1;
    }
}
