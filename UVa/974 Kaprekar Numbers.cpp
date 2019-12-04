#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, sq,cpy,a[100], zz;
    int i,j,x, multi, mini, maxi,TC,nl=0;
    bool kap;
    cin >> TC;
    for(zz = 1; zz <= TC; zz++){
            if(nl) cout << endl;
    cin >> mini >> maxi;
    kap = 0;
    printf("case #%d\n",zz);
    for(i = mini; i<=maxi; i++)
    {
       //cout << i << endl;
        sq = i*i;
        cpy = sq;
        j = 0;
        while(cpy != 0)
        {
            a[j++] = cpy %10;
            cpy /= 10;
          //  cout << a[j-1] << endl;
        }
       // cout << endl;
        for(int k=0; k < j-1; k++)
        {
            multi = 1;
            n1 = 0;
            n2 = 0;
           for(x=j-k-1; x <= j-1; x++)
            {
                n1 += multi *a[x];
                multi *= 10;
            }
            multi = 1;
            for(x=0; x < j-k-1; x++)
            {
                n2 += multi *a[x];
                multi *= 10;
            }
            if(n1 > 0 && n2 > 0)
            {
                if((n1+n2) == i){kap = 1;cout << i << endl;}
            }
        }
    }
    if(!kap) cout << "no kaprekar numbers" << endl;
    nl = 1;
    }
}
