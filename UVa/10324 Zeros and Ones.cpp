///Can Be more efficient by using cumulative sum
#include<bits/stdc++.h>
using namespace std;
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
int main()
{
    //FO;
    int n, j, a, b, x=0;
    bool Yes;
    string str;
    while(getline(cin, str))
    {
        //cout << "string =" << str <<"'" << endl;
        if(str.empty()) break;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b;
//            if(i != n-1) {cin >> a >> b;}
            //else{scanf("%d %d\n",&a , &b);}
            if(a>b)swap(a,b);
            int num = str[a];
            Yes = 1;
            for(int j=a; j<=b; j++)
            {
                if(num != str[j])
                {
                    Yes = 0;
                    break;
                }
            }
            if(i==0)printf("Case %d:\n",++x);
            if(Yes)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        char c = getchar();
    }
}
