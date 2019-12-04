///ACCEPTED :-)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> vec;
    int i,j,k,n,m,last,num ;
    while(scanf("%d",&num)==1 && num !=0)
    {
        last = m = 0 ;
    while(last !=2)
    {
        n = num;
        ++m;
        for(i=1; i<=n; i++)
        {
            vec.push_back(i);
        }
        j = 1;
        while(vec.size() !=1)
        {
            // cout <<"j = "<<j <<"  n = "<< n << endl;
            if(j>n && j%n==0)
            {
                j=n;
            }
            if(n!=j)
            {
                j = j % n;
            }

            vec.erase( vec.begin() + j-1 );

            n--;
            j += m;
            j--;
        }
        last = vec[0];
        vec.clear();
    }
    cout << m << endl;
    }
}
