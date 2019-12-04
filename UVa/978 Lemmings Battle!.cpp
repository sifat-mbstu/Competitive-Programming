#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> green, blue;
    multiset <int> set1, set2;
    long long ara1[100000];
    long long ara2[100000];
    int TC, B, gr, bl, GG, BB, n1, n2, sum_gr, sum_bl;
    cin >> B >> gr >> bl;
    GG = gr;
    BB = bl;
    while(GG--)
    {
        scanf("%d",&n1);
        green.push_back(n1);
    }
    sort(green.begin(), green.end());
    while(BB--)
    {
        scanf("%d",&n2);
        blue.push_back(n2);
    }
    sort(blue.begin(), blue.end());
    Min = min(bl,gr);
    j = B;
    if(bl > gr){

    }
    for(i = 0; i < B; i++)
    {
        j = i;
        while(j < Min)
        {
            ara1[i] += green[j];
            j += B;
        }
    }
    for(i = 0; i < B; i++)
    {
        j = i;
        while(j < Min)
        {
            ara2[i] += blue[j];
            j += B;
        }
    }
    sum_gr = sum_bl = 0;
    for(i = 0; i < B; i++)
    {
        if(ara1[i] > ara2[i]) { ara1[i] = ara1[i] - ara2[i]; ara2[i] = 0;}
        else if(ara2[i] > ara1[i]) { ara2[i] = ara2[i] - ara1[i]; ara1[i] = 0;}
        else if(ara2[i] == ara1[i]) { ara2[i] = 0; ara1[i] = 0;}
        sum_gr += ara1[i];
        sum_bl += ara2[i];
    }

}
