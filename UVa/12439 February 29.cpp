#include<bits/stdc++.h>
using namespace std;

int stm(char monthS[]) {
	if (strcmp(monthS, "January") == 0)
		return 1;
	if (strcmp(monthS, "February") == 0)
		return 2;
	if (strcmp(monthS, "March") == 0)
		return 3;
	if (strcmp(monthS, "April") == 0)
		return 4;
	if (strcmp(monthS, "May") == 0)
		return 5;
	if (strcmp(monthS, "June") == 0)
		return 6;
	if (strcmp(monthS, "July") == 0)
		return 7;
	if (strcmp(monthS, "August") == 0)
		return 8;
	if (strcmp(monthS, "September") == 0)
		return 9;
	if (strcmp(monthS, "October") == 0)
		return 10;
	if (strcmp(monthS, "November") == 0)
		return 11;
	if (strcmp(monthS, "December") == 0)
		return 12;
	return -1;
}

int main()
{
        //freopen("input.txt","r",stdin);

    char m1[100],m2[100],c;
    int D1,D2,Y1,Y2,M1,M2,i,cnt,TC,k;
    scanf("%d",&TC);
    c = getchar();
    for(k=1;k<=TC;k++)
    {
    scanf("%s %d, %d",m1,&D1,&Y1);
    scanf("%s %d, %d",m2,&D2,&Y2);
    cnt = 0;
    //printf("%s %s %d %d",m1,m2,Y1,Y2);
    M1 = stm(m1);
    M2 = stm(m2);
    for(i=Y1;i<=Y2;i++)
    {
        if((i%400)==0 || ((i%4==0) && (i % 100 !=0)))
        {
            if (i==Y1 && i==Y2 ){if(M1 < 2 && M2 >2){cnt++;}
            else if(M1 ==2 && D1 == 29){cnt++; }
            else if(M2 ==2 && D2 == 29){cnt++; }
            }
           // printf("Yes...i = %d\n",i);
            else if(i==Y1)
            {
                    if(M1 < 2) cnt++;
                    else if ( M1 == 2 && D1 == 29)
                    {
                         cnt++;
                    }
            }
            else if (i==Y2)
            {
                if(M2 > 2) cnt++;
                else if ( M2 == 2 && D2 == 29)

                        { cnt++;}

            }
            else {cnt++;}
        }
    }
    printf("Case %d: %d\n",k,cnt);
    }
}
