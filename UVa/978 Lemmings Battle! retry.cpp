#include <bits/stdc++.h>
using namespace std ;
int main(){
 multiset <int > G , B ;
 multiset <int> :: iterator fit ,it ;
 vector < int > storeG , storeB ;
 int n , i  ,  j , k , x , y ,battles , ng ,nb;
 scanf("%d",&n);
  while ( n-- ){
         G.clear ()  ; B.clear() ;
         storeB.clear() ; storeG.clear() ;
       scanf("%d %d %d" , &battles ,&ng ,&nb);
       for ( i = 0 ; i < ng ; i++)
       {
             scanf("%d",&x);
             G.insert ( x );
       }
       for ( i = 0 ; i < nb; i++)
       {
             scanf("%d",&x);
             B.insert ( x );
       }
      while ( G.size() > 0 && B.size() > 0)
      {     storeG.clear() ; storeB.clear() ;
             for ( i = 0 ; i < battles ; i++)
              {
                    it = G.end() ; it -- ;
                    fit = B.end() ; fit-- ;
                    if ( *it > *fit)
                    {
                          G.erase(it); B.erase(fit);
                          storeG.push_back ( *it - *fit);
                    }
                    else if ( *it < *fit)
                    {
                          G.erase(it); B.erase(fit);
                          storeB.push_back ( *fit - *it);
                    }
                    else
                        {
                            G.erase(it); B.erase(fit);
                        }
                    if (G.size() == 0 || B.size() == 0)
                    break ;
              }
              for ( int z = 0 ; z < storeB.size() ; z++)
                        B.insert( storeB [z] );
              for ( int z = 0 ; z < storeG.size() ; z++)
                     G.insert ( storeG [z] );
      }
      if ( G.size() == 0 && B.size() == 0)
      {
           printf("green and blue died\n");
      }
      else if (G.size() > 0)
      {
          printf("green wins\n");
            it = G.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while ( it != G.begin());
      }
      else if (B.size() > 0)
      {
          printf("blue wins\n");
          it = B.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while (it != B.begin());
      }
      if (n)
      printf("\n");
  }
    return 0;
}
