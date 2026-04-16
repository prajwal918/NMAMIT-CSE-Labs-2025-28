#include <stdio.h>
#include <string.h>
int string_match ( char t [] , char p []) {
int i , j , m , n ;
n = strlen ( t ) ;
m = strlen ( p ) ;
for ( i =0; i <= n - m ; i ++) {
j = 0;
while ( j < m && p [ j ] == t [ i + j ]) {
j ++;
}
if ( j == m )
return i ;
}
return -1;
}

int main () {
char t [100] , p [50];
int pos ;

printf ("Enterthetext:" ) ;
scanf ("%s" , t ) ;
printf ("Enterthepattern:" ) ;
scanf ("%s" , p ) ;

pos = string_match (t , p ) ;

if ( pos == -1)
printf ("Patternnotfound\n" ) ;
else
printf ("Patternfoundatposition%d\n" , pos +1) ;

return 0;
}
