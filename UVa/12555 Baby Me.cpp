///Not accepted
    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int TC,i;
        double a,b,res;
       string s;
       cin >> TC;
       getchar();
       for(i=1;i<=TC;i++){
       getline(cin, s);
       if(s.length() == 8)
       {
           a = 10;
           b =s[5] - '0';
           res = a * 0.5 + b * 0.05;
       }
       else if (s.length() == 7)
       {
           a =s[0] - '0';
           b =s[4] - '0';
           res = a * 0.5 + b * 0.05;
      }
       else if (s.length() == 4)
       {
           a = 10;
           res = a * 0.5;
       }
       else if(s.length() == 3)
       {
           a =s[0] - '0';
           res = a * 0.5;
       }
       printf("Case %d: ",i);
        cout << res <<endl;
       }
    }
