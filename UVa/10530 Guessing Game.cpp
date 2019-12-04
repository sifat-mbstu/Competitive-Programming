#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c,s[100];
    //string s;
    int hi[10000], lo[10000], n, honest,i,j;
    i = 0;
    j = 0;
    while((scanf("%d",&n)==1))
    {
        if(n == 0)
        {
            break;
        }

        c = getchar();
        // cout <<"i =" << i <<" j =" << j <<" n ==" << n << endl;
        //if (n == 0) {break;}
        gets(s);
        //cout << s;
        if(strcmp(s,"too low")== 0)
        {
            lo[i] = n;
            i++;
        }
        else if(strcmp(s,"too high")==0)
        {
            //  cout << "Yes";
            hi[j] = n;
            j++;
        }
        else if(strcmp(s,"right on")==0)
        {
            sort(lo, lo+i);
            sort(hi, hi+j);
            if(j == 0 && i!=0)
            {
                if(n > lo[i-1]){honest = 1;}
                else {honest = 0;}
            }
            else if(i == 0 && j!=0)
            {
                if(n < hi[0]){ honest = 1;}
                else {honest = 0;}
            }
            else if (i > 0 && j > 0)
            {
                if(n > lo[i-1] && n < hi[0])
                {
                    honest = 1;
                }
                else
                {
                    honest = 0;
                }
            }
            else
            {
                honest = 1;
            }
            i = j = 0;
            if(honest)
            {
                //cout <<"s =" << s <<endl;
                printf("Stan may be honest\n");
            }
            else
            {
                //cout <<"s =" << s <<endl;
                printf("Stan is dishonest\n");
            }
        }
    }
}
