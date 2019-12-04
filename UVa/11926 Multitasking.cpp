#include<bits/stdc++.h>
using namespace std;
bool ara[1000005],t;
void SetRepeatAra(int a, int b, int inter)
{
    int i, j;
    int dif = b - a;
    for(i = a; i < 1000001; i += inter)
    {
        //cout << i << endl;
        if(ara[i] == 1 || ((i+dif) < 1000001 && ara[i+dif] ==1)){ t = 1;}
        int m = i + dif;
        if(m > 1000001) {m = 1000001;}
        for(j = i; j < m ; j++)
        {
            //cout << j << endl;
            if(ara[j] == 1){ t = 1;}
            ara[j] = true;
        }
    }
}
void SetAra(int a, int b)
{
    int i;
    if(ara[a] ==1 || ara[b] == 1){ t = 1;}
    for(i=a; i < b && i < 1000001; i++)
    {
        if(ara[i] == 1){t = 1;}
        ara[i] = true;
    }
}
int main()
{
    int N, R,inter,a,b,i;
    while(cin >> N >> R){
            if(!N && !R){break;}
    memset(ara, 0, sizeof(ara));
    t = 0;
    for(i=0; i<N; i++)
    {
        cin >> a >> b;
        SetAra(a,b);
    }
    for(i=0; i<R; i++)
    {
        cin >> a >> b >> inter;
        SetRepeatAra(a,b,inter);
    }
    if(t){cout << "CONFLICT" << endl;}
    else {cout << "NO CONFLICT" << endl;}
    }
    return 0;
}
