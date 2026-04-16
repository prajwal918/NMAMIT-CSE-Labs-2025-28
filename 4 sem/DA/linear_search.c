#include <stdio.h>
int linear_search ( int a [] , int n , int key ) {
int i ;
for ( i =0; i < n ; i ++) {
if ( a [ i ] == key )
return i ;
}
return -1;
}
int main () {
int a [100] , n , i , key , pos ;
printf ("Enterthenumberofelements:" ) ;
scanf ("%d" , & n ) ;
printf ("Entertheelements:" ) ;
for ( i =0; i < n ; i ++)
scanf ("%d" , & a [ i ]) ;

printf ("Enterthekeyelementtosearch:" ) ;
scanf ("%d" , & key ) ;

pos = linear_search (a , n , key ) ;

if ( pos == -1)
printf ("Elementnotfound\n" ) ;
else
printf ("Elementfoundatposition%d\n" , pos +1) ;

return 0;
}
