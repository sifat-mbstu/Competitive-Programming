    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    int main()
    {
        ll An,A,L,counts,test=0;
        while(scanf("%lld %lld",&A,&L)==2)
        {
            An = A;
            if(A<0 && L<0){break;}
            counts = 1;
            while(A!=1)
            {
                counts++;
                if(A%2==0)
                {
                    A/=2;
                }
                else
                {
                    A = 3*A + 1;
                }
                if(A>L)
                {
                    counts--;
                    break;
                }
            }
            printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++test,An,L,counts);
        }
    }
