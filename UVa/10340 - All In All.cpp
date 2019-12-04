#include<bits/stdc++.h>
using namespace std;
#define Max 1000000
char str_1[Max],str_2[Max];
int main()
{
    long long int i,j,len_1,len_2,k;
    while(scanf("%s %s",str_1,str_2)==2)
    {
    len_1=strlen(str_1);
    len_2=strlen(str_2);
    //printf("str_2____%lld\n",len_2);
    if(len_1>len_2){printf("No\n");}
    else{
    j=-1;
    k=-1;
    for(i=0;i<len_1;++i)
    {
        while(j<len_2-1)
        {
            j++;
            if(str_1[i]==str_2[j])
            {
                k=i;
                break;
            }

        }
    }
    //printf("len1=%lld  len2=%lld i = %lld  j=%lld k=%lld\n",len_1,len_2,i,j,k);
    if(k==i-1){printf("Yes\n");}
    else{printf("No\n");}
    }
    }
}
