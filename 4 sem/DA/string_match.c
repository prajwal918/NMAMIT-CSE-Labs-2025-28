# include < stdio .h >
# include < string .h >
int s t r i n g _ m a t c h ( char t [] , char p []) {
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

printf ( " Enter the text : " ) ;
scanf ( " % s " , t ) ;
printf ( " Enter the pattern : " ) ;
scanf ( " % s " , p ) ;

pos = s t r i n g _ m a t c h (t , p ) ;

if ( pos == -1)
printf ( " Pattern not found \ n " ) ;
else
printf ( " Pattern found at position % d \ n " , pos +1) ;

return 0;
}
