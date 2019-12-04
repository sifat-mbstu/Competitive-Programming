#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FI freopen ("input.txt", "r",stdin)
#define FO freopen ("output.txt", "w",stdout)
int main()
{
    //FI;
    char ch;
    map <char, int>Map;
    string s;
    ll TC, n,num,i,sum;
    cin >> TC;
    while(TC--){
    sum = 0;
    cin >> n;
    ch = getchar();
    Map.clear();
    for(i = 0; i < n; i++){
    scanf("%c %d ",&ch, &num);
    //printf("%c %d\n",ch, num);
    Map[ch] = num;
    }
    cin >> n;
    sum = 0;
     ch = getchar();
    for(i = 0; i < n; i++)
    {
        getline (cin , s);
        //cout << s << endl;
        int len = s.size();
        for(int j = 0; j < len; j++)
        {
            //cout << j << endl;
            if(Map.count(s[j]) > 0)
            {
                //printf("c = %c\n",s[j]);
                sum += Map[s[j]];
            }
        }
    }
    //cout << sum << endl;
    double res = (double)sum / 100.0;
    printf("%.2lf$\n",res);
    }
}
