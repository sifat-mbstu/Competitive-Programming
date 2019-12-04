#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000][1000],c;
    int len,TC,count_right,count_left,i,j,a,k;
    scanf("%d",&len);
    //c = getchar();
    for(k=0;k<len;k++)
    {
        scanf("%s",&str[k]);
    }

    scanf("%d",&TC);
    while(TC--)
    {
        count_right = count_left = 0 ;
        scanf("%d",&i);
        i--;
        if(strcmp(str[i] , "?") !=0)
        {
            printf("%s\n",str[i]);
        }
        else
        {
            for(j = i; j<len && (strcmp(str[j],"?")==0);j++)
            {
                count_right++;
                if(j==len-1 && (strcmp(str[j] ,"?")== 0)){count_right = 200;}
            }
            for(j = i; j >= 0 && (strcmp(str[j],"?")==0);j--)
            {
                count_left++;
                if(j==0 && (strcmp(str[j],"?")==0)){count_left = 200;}
            }

            if(count_right == count_left)
            {
                printf("middle of %s and %s\n",str[i-count_left],str[i+count_left]);
            }
            else if (count_right > count_left)
            {
                a = count_left;
                while(a--)
                {
                    printf("right of ");
                }
                printf("%s\n",str[i-count_left]);
            }

            else if (count_left > count_right)
            {
                a = count_right;
                while(a--)
                {
                    printf("left of ");
                }
                printf("%s\n",str[i+count_right]);
            }
        }
    }
}
