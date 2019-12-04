///Have to submit
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    string s,res;
    int N, len, multi, sum, i, j, x, TC;
    scanf("%d",&TC);
    for(x=1; x<=TC; x++)
    {
        cin >> s;
        res.clear();
        len = s.size();
        j = 0;
        for(i=0; i<len; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                ch = s[i];
            }
            else
            {
                multi = 1;
                sum = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    int num = s[i] - '0';
                    sum = sum*multi + num;
                    multi *= 10;
                    i++;
                    if(i>=len)break;
                }
                i--;
                while(sum--)
                {
                    res.push_back(ch);
                }
            }
        }
        printf("Case %d: ",x);
        cout << res << endl;
    }
}
