#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a,n,s,i;
    while(cin>>n)
    {
        vector<int>v;
        if(n==0)
        return 0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a) v.push_back(a);
        }
        int l=v.size();
        if(!l) cout<<"0";
        else
        {
            for(int i=0;i<l;i++)
            {
                if(i) cout<<" ";
                cout<<v[i];
            }

        }
        cout<<endl;
    }
return 0;
}
