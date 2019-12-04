#include<bits/stdc++.h>
using namespace std;
int main()
{
    char song[50][20],people[110][110],c;
    int i,j,k,N;
    strcpy(song[0]," Happy");
    strcpy(song[1]," birthday");
    strcpy(song[2]," to");
    strcpy(song[3]," you");

    strcpy(song[4]," Happy");
    strcpy(song[5]," birthday");
    strcpy(song[6]," to");
    strcpy(song[7]," you");

    strcpy(song[8]," Happy");
    strcpy(song[9]," birthday");
    strcpy(song[10]," to");
    strcpy(song[11]," Rujia");

    strcpy(song[12]," Happy");
    strcpy(song[13]," birthday");
    strcpy(song[14]," to");
    strcpy(song[15]," you");

    scanf("%d",&N);
    c = getchar();
    for(i=0;i<N;i++)
    {
        gets(people[i]);
    }
    j=0;
    int lim = 16;
    while(N>lim){lim *= 2;}
    for(i=0,k=0;i<lim;i++,k++)
    {
        printf("%s",people[j]);
        j++;
        if(j==N){j=0;}
        printf(":");
        puts(song[k]);
        if(k==15){k=-1;}
        //printf("k = %d\n",k);
    }

    return 0;
}
