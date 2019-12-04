#include<stdio.h>
int main()
{
    double space,pre,fin_pre,sum,f_y,ani,env_fnd;
    int i,n,N,j;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        sum=0;
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%lf %lf %lf",&f_y,&ani,&env_fnd);
            space=f_y/ani;
            pre=space*env_fnd;
            fin_pre=pre*ani;
            sum=sum+fin_pre;
        }
        printf("%ld\n",(long int)sum);
    }
    return 0;
}
