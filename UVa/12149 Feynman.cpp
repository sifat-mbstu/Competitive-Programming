#include<bits/stdc++.h>
using namespace std;

int sq(int num)
{
    int res=0;
    if (num<1){return res;}
    int sqr = num*num;
    //printf("sqr = %d\n",sqr);
    return res = sqr + sq(num-1);
}
int main()
{
    int get_num;
    while((scanf("%d",&get_num)==1) && get_num!=0){
    int res = sq(get_num);
    printf("%d\n",res);
    }
}
