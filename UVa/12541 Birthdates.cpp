#include<bits/stdc++.h>
using namespace std;
int main()
{
    char name[150][20],c;
    int N,i,day,month,year,Days[150],Max,Min;
    scanf("%d",&N);
    c = getchar();
    for(i=0;i<N;i++)
    {
        scanf("%s",&name[i]);
        //c = getchar();
        scanf("%d",&day);
        scanf("%d",&month);
        scanf("%d",&year);
        Days[i] = day + month*12 + year*365;
    }
    int youngest=0;
    int oldest = 0;
    Max = Days[0];
    Min = Days[0];
    for(i=0;i<N;i++)
    {
        //printf("\nDays = %d\n",Days[i]);
        if(Days[i]>Max){Max = Days[i];youngest = i;}
        else if(Days[i]<Min){Min = Days[i];oldest = i;}
    }
    printf("%s\n",name[youngest]);
    printf("%s\n",name[oldest]);
    //printf("Min = %d Max = %d", Min, Max);
}
