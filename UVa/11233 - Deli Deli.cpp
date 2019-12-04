#include<bits/stdc++.h>
using namespace std;
int main()
{
    int L,N,i,j,k,x;
    string str[100], given;
    while(scanf("%d %d",&L,&N)==2)
    {
        k = 0;
        for(i=0; i<L; i++)
        {
            cin >> str[k] >> str[k+1] ;
            k += 2;
        }

        for(i=0; i<N; i++)
        {
            x = 0;
            cin >> given;
            int len = given.size();

            for(j=0; j<L*2-1; j+=2)
            {
                if(str[j] == given)
                {
                    cout << str[j+1] << endl;
                    x++;
                }
            }
            if(x ==0)
            {
                if(given[len-1] == 'y' && given[len-2] != 'a' && given[len-2] != 'e' && given[len-2] != 'i' && given[len-2] != 'o' && given[len-2] != 'u')
                {
                    given.replace(len-1,1,"ies");
                    cout << given << endl;
                }

                else if(given[len-1] == 'o' || given[len-1] == 's' || given[len-1] == 'x')
                {
                    given.replace(len,1,"es");
                    cout << given << endl;
                }
                else if((given[len-2] == 'c' &&  given[len-1] == 'h' ) || (given[len-2] == 's' && given[len-1] == 'h'))
                {
                    //  cout << "Hmm" <<endl;
                    given.replace(len,2,"es");
                    cout << given << endl;
                }
                else
                {
                    given.replace(len,1,"s");
                    cout << given << endl;
                }
            }
        }
    }
}
