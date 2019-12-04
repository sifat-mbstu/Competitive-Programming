#include<bits/stdc++.h>
using namespace std;

int check_vowel( char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char str_1[100], str_2[100],c;
    int i,j,k,len_1,len_2,TC,res;
    cin >> TC;
    c = getchar();
    while(TC--)
    {
        gets(str_1);
        gets(str_2);
        res = 1;
        len_1 = strlen(str_1);
        len_2 = strlen(str_2);
        if(len_1 == len_2)
        {
            for(i=0; i<len_1; i++)
            {
                if(check_vowel(str_1[i]))
                {
                    if(check_vowel(str_2[i])==0)
                    {
                        res = 0;
                        break;
                    }
                    /*else
                    {
                        res = 0;
                        break;
                    }*/
                }
                else
                {
                    if(str_1[i] != str_2[i])
                    {
                        res = 0;
                        break;
                    }
                }
            }
        }
        else
        {
            res = 0;
        }

        if(res)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
