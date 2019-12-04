#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[20],C;
    int num,one,two,three;
    scanf("%d",&num);
    C=getchar();
    while (num--){
    one=two=three=0;
    gets(str);

    if(str[0]=='o'){one++;}
    else if(str[0]=='t'){two++;}
    else if(str[0]=='t'){three++;}

    if(str[1]=='n'){one++;}
    else if(str[1]=='w'){two++;}
    else if(str[1]=='h'){three++;}

    if(str[2]=='e'){one++;}
    else if(str[2]=='o'){two++;}
    else if(str[2]=='r'){three++;}

    if(one>=2){printf("1\n");}
    else if(two>=2){printf("2\n");}
    else {printf("3\n");}
    }

    return 0;
}
