#include<bits/stdc++.h>
using namespace std;
#define mx 100100
int a1[2*mx], a2[2*mx];
void make_pattern()
{
    int x=0,y=1, j;
    int ind = 3;
    a1[1] = 0;
    a2[1] = 0;
    a1[2] = 0;
    a2[2] = 1;
    //
    for(int i=1;ind < mx-50; i++)
    {
        ///left up
        for(j=0; j<i; j++)
        {
            //if(ind == 10) {cout << "---------->" << "  ";}
            a1[ind] = --x;
            a2[ind] = y;
            ind++;
            //cout << "\n\ny====" << y << endl;
             //printf("ind-1 = %d a1[ind-1] = %d a2[ind-1] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);
            //cout << a1[ind-1] << endl;
        }
        ///up
        for(j=0; j<i; j++)
        {
            --y;
            a1[ind] = x;
            a2[ind++] = y;
            //printf("ind = %d a1[ind] = %d a2[ind] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);
        }
        ///right-up
        for(j=0; j<i; j++)
        {
            ++x;--y;
            a1[ind] = x;
            a2[ind++] = y;
            //printf("ind = %d a1[ind] = %d a2[ind] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);
        }
        ///Down-right
        for(j=0; j<i; j++)
        {
            ++x;
            a1[ind] = x;
            a2[ind++] = y;
            //printf("ind = %d a1[ind] = %d a2[ind] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);

        }
        ///Down
        for(j=0; j<i+1; j++)
        {
            ++y;
            a1[ind] = x;
            a2[ind++] = y;
            //printf("ind = %d a1[ind-1] = %d a2[ind-1] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);
        }
        ///Down-left
        for(j=0; j<i; j++)
        {
            --x;++y;
            a1[ind] = x;
            a2[ind++] = y;
            //printf("ind = %d a1[ind] = %d a2[ind] = %d\n\n",ind-1, a1[ind-1], a2[ind-1]);
        }
    }
}
int main()
{
    make_pattern();
    int ind;
    while(cin >> ind){
    cout << a1[ind] << " " << a2[ind] << endl;
    }
}
