#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,S,ara[20];
    cin >> S;
    for(i=1;i<=S;i++)
    {
        for(j=0;j<13;j++)
        {
            cin >> ara[j];
        }
        sort(ara, ara+13);
        if(ara[0]>0){cout << "Set #" << i <<": Yes" << endl; }
        else {cout << "Set #" << i <<": No" << endl; }
    }
}
