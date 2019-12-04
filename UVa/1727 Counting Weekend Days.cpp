#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s1, s2;
    map<string, int> Month;
    map<string, int> Day;
    Month["JAN"] = 31;
    Month["FEB"] = 28;
    Month["MAR"] = 31;
    Month["APR"] = 30;
    Month["MAY"] = 31;
    Month["JUN"] = 30;
    Month["JUL"] = 31;
    Month["AUG"] = 31;
    Month["SEP"] = 30;
    Month["OCT"] = 31;
    Month["NOV"] = 30;
    Month["DEC"] = 31;

    Day["SUN"] = 1;
    Day["MON"] = 2;
    Day["TUE"] = 3;
    Day["WED"] = 4;
    Day["THU"] = 5;
    Day["FRI"] = 6;
    Day["SAT"] = 7;
    int tc;
    scanf("%d",&tc);
    while(tc--){
    cin >> s1 >> s2;
    int cnt = 0;
    int mon = Month[s1];
    int day = Day[s2];
    for(int i=day; i<day+mon; i++)
    {
        if(i%7 == 6 || i%7 == 0){cnt++;}
    }
    printf("%d\n",cnt);
}
}
