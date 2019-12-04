#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t1,t2,c1,c2,c3,a,f,test,avg,i,sum;
    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        sum=0;
        scanf("%d%d%d%d%d%d%d",&t1,&t2,&f,&a,&c1,&c2,&c3);
        if(c1>=c2){if(c2>=c3){avg=(c1+c2)/2;}
                    else{avg=(c1+c3)/2;}
                    }
        else if(c2>=c1){if(c1>=c3){avg=(c1+c2)/2;}
                        else{avg=(c3+c2)/2;}}
                        //printf("avg==%d\n",avg);
        sum = t1+t2+f+a+avg;
        //printf("sum=%d\n",sum);
        if(sum>=90)
            printf("Case %d: A\n",i);
        else if(sum>=80)
            printf("Case %d: B\n",i);
        else if(sum>=70)
            printf("Case %d: C\n",i);
        else if(sum>=60)
            printf("Case %d: D\n",i);
        else if(sum<60)
            printf("Case %d: F\n",i);
    }
    return 0;

}
