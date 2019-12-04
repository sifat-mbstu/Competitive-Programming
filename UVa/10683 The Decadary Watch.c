#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[20];
    double total_time;
    int i,times[20],New_time[20],num,New,hour,min,sec,cc,Need;
    while(gets(str))
    {
        for(i=0; i<8; i++)
        {
            num = str[i]-'0';
            times[i] = num;
        }
        hour = times[1] + times [0]*10;
        min = times[3] + times [2]*10;
        sec = times[5] + times [4]*10;
        cc = times[7] + times [6]*10;
        total_time = cc+sec*100+min*6000+hour*360000;
        for(i=0; i<4; i++)
        {
            New_time[i]=0;
        }

        total_time =(total_time * 125)/108;
        Need = floor(total_time);

        printf("%07d\n", Need);
    }
    return 0;
}
