#include <stdio.h>
int main()
{
    char grade;
    int i,j,sum,N,CT;
    int Marks[7];
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        sum=0;
        for(j=0; j<7; j++)
        {
            scanf("%d",&Marks[j]);
            sum=sum+Marks[j];
        }
        sum=sum-Marks[4]-Marks[5]-Marks[6];
        CT=(Marks[4]+Marks[5]+Marks[6])/3;
        sum=sum+CT;
        if(sum>=90 && sum <=100)
        {
            grade = 'A';
        }
        else if(sum>=80 && sum <90)
        {
            grade = 'B';
        }
        else if(sum>=70 && sum <80)
        {
            grade = 'C';
        }
        else if(sum>=60 && sum <70)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
        printf("Case %d: %c\n",i,grade);
    }
    return 0;
}
