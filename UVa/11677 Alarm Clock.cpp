#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H1,M1,H2,M2,i=0;
    scanf("%d %d %d %d",&H1,&M1,&H2,&M2);
    while(H1!=H2){if(H1==23){i=0;}i++;H1++;}
    printf("%d",i);

}
