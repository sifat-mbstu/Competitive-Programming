 ///This a Program to Check Cube Number

#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long int Cube_Root(ll n)
{
    double g,a,g1;
    int check,check1;
    a = double(n);
    g1 = 0;
    g = sqrt(a);
    while(1)
    {
        g = ((2.0/3.0)*g)+((1.0/3.0)*(a/(g*g)));
        if((g1/g)==1.0){break;}
        g1 = g;
    }
    check1 = g1;
    return g1;
}

int Check_Cube_Root(ll n)
{
    double g,a,g1;
    long long int check,check1;
    a = double(n);
    g1 = 0;
    g = sqrt(a);
    while(1)
    {
        g = ((2.0/3.0)*g)+((1.0/3.0)*(a/(g*g)));
        if((g1/g)==1.0){break;}
        g1 =g;
    }
    g1 *= 100;
    check = (int)g;
    check *= 100;
    check1 = (int)g1;
    if(check1==check){return 1;}
    else{return 0;}
}
int main()
{
    //freopen("input.txt","r",stdin);
    ll N,ini,i,cube,t;
    while (scanf("%lld",&N))
    {
    if(N == 0){break;}
    t = 0;
    ini = Cube_Root(N);
    for(i = ini;i <= 60; i++)
    {
        cube = i*i*i;
        if(cube>N){
            if(Check_Cube_Root(cube-N))
            {
                t = 1;
                printf("%lld %lld\n",i, Cube_Root(cube-N));
                break;
            }
        }
    }
    if(!t){printf("No solution\n");}
    }
}
