#include <math.h>
#include <stdio.h>

int nCr(int n, int r) {
   if(r>n) {
      printf("FATAL ERROR"); return 0;
     }
   if(n==0 || r==0 || n==r) {
      return 1;
   } else {
      return (int)lround( ((double)n/(double)(n-r)/(double)r) * exp(lgamma(n) - lgamma(n-r) - lgamma(r)));
   }
}


int nPr(int n, int r) {
   if(r>n) {printf("FATAL ERROR"; return 0;}
   if(n==0 || r==0) {
      return 1;
   } else {
      if (n==r) {
         r = n - 1;
      }
      return (int)lround( ((double)n/(double)(n-r)) * exp(lgamma(n) - lgamma(n-r)));
   }
}

int main()
{

}
