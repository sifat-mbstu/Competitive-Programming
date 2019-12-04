#include<bits/stdc++.h>
using namespace std;
int main()
{
    double tax,num;
    long long i,T,Z,cases;
    cin >> cases;
    for(i=1;i<=cases ;i++){
    scanf("%lf",&num);
    tax =0.0;
    if(num > 180000.0) {
    num = num - 180000.0;

    //cout << "Num = " << num << "  Tax = " << tax << endl;

    if(num >= 300000.0) { tax += 30000.0; num -= 300000.0;}
    else{ tax += num * 0.10; num = 0.0;}

    //cout << "Num = " << num << "  Tax = " << tax << endl;

    if(num >= 400000.0) { tax += 60000.0 ; num -= 400000.0;}
    else { tax += num * 0.15; num = 0.0;}

    //cout << "Num = " << num << "  Tax = " << tax << endl;

    if(num >= 300000.0) { tax += 60000.0 ; num -= 300000.0;}
    else { tax += num * 0.20; num = 0.0;}

    //cout << "Num = " << num << "  Tax = " << tax << endl;
    //cout << tax << endl;

    if(num > 0.0) {tax += num * 0.25; num = 0.0;}
   // printf("Tax = %lf\n",tax);
    }

    if(tax > 0.0 && tax < 2000.0){tax =2000.0;}


   T=static_cast<int>(tax); //cout<<T<<endl<<tax<<endl;
         if(T < tax) T++;


    cout << "Case " << i <<": " << T << endl;
    }
}
