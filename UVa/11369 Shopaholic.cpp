#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[20100], TC, N, i, sum;
    cin >> TC;
    while(TC--){
    cin >> N;
    ara[0] = -2100000;
    for(i = 1; i <= N; i++)
    {
        cin >> ara[i];
        ara[i] *= -1;
    }
    sort(ara,ara+N+1);/*
    for(i = 1; i <= N; i++)
    {
        cout <<  ara[i] << endl;
    }
*/
    sum = 0;
    for(i = 3; i <= N; i += 3)
    {
        //cout << ara[i] << endl;
        sum += ara[i];
    }
    sum *= -1;
    cout << sum << endl;
    }
}
