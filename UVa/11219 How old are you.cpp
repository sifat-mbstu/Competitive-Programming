#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("i.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    long long int i,TC, age,diff_sum,pre_month,pre_year,pre_date,birth_date,birth_month,birth_year, birth_sum,pre_sum;
    char c;
    while(scanf("%lld",&TC)==1){
    for(i=1;i<=TC;i++){
    //c = getchar();
    scanf("%lld/%lld/%lld",&pre_date,&pre_month,&pre_year);
    //printf("%d/%d/%d\n",pre_date,pre_month,pre_year);
    scanf("%lld/%lld/%lld",&birth_date,&birth_month,&birth_year);

    //if(pre_month == 2 && pre_date ==29){pre_date = 28;}
    //if(birth_month == 2 && birth_date ==29){birth_date = 28;}

    if(pre_date < birth_date)
    {
        pre_month--;
    }
    if(pre_month < birth_month)
    {
        pre_year--;
    }
    age = pre_year- birth_year;

    if(age<0){printf("Case #%lld: Invalid birth date\n",i);}
    else if(age > 130){printf("Case #%lld: Check birth date\n",i);}
    else
        {
            printf("Case #%lld: %lld\n",i,age);
        }
    }
}
}
