#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int pos,n,TC;
    string str,sub,check;
    scanf("%d",&TC);
    c = getchar();
    while(TC--)
    {
        getline(cin, str);
        scanf("%d",&n);
        c = getchar();
        while(n--)
        {
            getline(cin, sub);
            check(str, 0, sizeof(sub));
            if(pos>=0)
            {
                printf("y\n");
            }
            else
            {
                printf("n\n");
            }
        }
    }
}
