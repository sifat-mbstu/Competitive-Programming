/*ACCEPTED*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <int, char> Map;
    int TC, len,ara[20000],i;
    cin >> TC;
    while(TC--)
    {
    string str;
    cin >> str;
    len = str.size();
    for(i=0; i < len; i++)
    {
        int num = str[i];
        if(num >= 'A' && num <= 'Z')
        {
            num *= 2;
        }
        else{
            num = 131+ 2*(num-'a');
        }
    Map[num] = str[i];
    ara[i] = num;
    }
    sort(ara,ara+len);
    do
    {
        for(i=0; i<len; i++)
        {
            cout << Map[ara[i]];
        }
        cout <<endl;
    }   while(next_permutation(ara,ara+len));
    }
    return 0;
}
/*
#include <iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

int main ()
{
    map<int,char>M;
    int n,i,j,l,d,a[100];
    char c[100];
    string s;
  cin>>n;
  for(i=0;i<n;i++)
  {
      cin>>s;
      l=s.size();
      for(j=0;j<l;j++)
      {
          d=s[j];
          if(d>64 && d<91)
          d=d*2;
          else
          d=131+2*(s[j]-97);
          M[d]=s[j];
          a[j]=d;
      }
      sort(a,a+l);


      do {
            for(j=0;j<l;j++)
            cout <<M[a[j]];
            cout<<endl;
        } while ( next_permutation (a,a+l) );
  }
return 0;
}
*/


/**
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <cstdlib>
    #include <cstring>
    using namespace std;
    char in[1000];
    int cmp(const void *a, const void*b)
    {
        return *(char*)a-*(char*)b;
    }
    bool comp(const char &a, const char &b)
    {
        int delta = tolower(a) - tolower(b);
        return delta?delta<0:a<b;
    }
    int main()
    {
        int test, len;
        scanf("%d",&test);
        getchar();
        while (test--)
        {
            gets(in);
            len = strlen(in);
            sort(in,in+len,comp);
            do
            {
                cout << in << endl;
            } while (next_permutation(in,in+len,comp));
        }
        return 0;
    }
*/

