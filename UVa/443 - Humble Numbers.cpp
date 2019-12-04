#include<iostream>
#include<cstdio>
using namespace std;
#define Max 5842
long humble[5845];
long MIN(long a, long b,long c, long d)
{
    if(a<=b && a<=c && a<=d)
        return a;
    else if(b<=a && b<=c && b<=d)
        return b;
    else if(c<=a && c<=b && c<=d)
        return c;
    else
        return d;
 }

void HumbleNumber()
{
    int i,i2=1,i3=1,i5=1,i7=1;
    long next_2=2,next_3=3,next_5=5,next_7=7;

    humble[1]=1;

    for(i=2; i<=Max; i++)
    {
        //printf("%d %d %d\n",i2,i3,i5);
        humble[i]=MIN(next_2,next_3,next_5,next_7);

        if(humble[i]==next_2)
        {
            i2++;
            next_2=2*humble[i2];
        }
        if(humble[i]==next_3)
        {
            i3++;
            next_3=3*humble[i3];
        }
        if(humble[i]==next_5)
        {
            i5++;
            next_5=5*humble[i5];
        }
        if(humble[i]==next_7)
        {
            i7++;
            next_7=7*humble[i7];
        }
     }
}

int main()
{
    //freopen("out.txt","w",stdout);
    HumbleNumber();

    int N;

    while(cin >> N && N)
    {
        if(N%10==1 && (N%100)/10 != 1){printf("The %dst humble number is %ld.\n",N,humble[N]);}
        else if(N%10==2 && (N%100)/10 != 1){printf("The %dnd humble number is %ld.\n",N,humble[N]);}
        else if(N%10==3 && (N%100)/10 != 1){printf("The %drd humble number is %ld.\n",N,humble[N]);}
        else {printf("The %dth humble number is %ld.\n",N,humble[N]);}
    }

    return 0;
}
