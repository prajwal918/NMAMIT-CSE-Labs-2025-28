# include < stdio .h >
int l i n e a r _ s e a r c h ( int a [] , int n , int key ) {
int i ;
for ( i =0; i < n ; i ++) {
if ( a [ i ] == key )
return i ;
}
return -1;
}
int main () {
int a [100] , n , i , key , pos ;
printf ( " Enter the number of elements : " ) ;
scanf ( " % d " , & n ) ;
printf ( " Enter the elements : " ) ;
for ( i =0; i < n ; i ++)
scanf ( " % d " , & a [ i ]) ;

printf ( " Enter the key element to search : " ) ;
scanf ( " % d " , & key ) ;

pos = l i n e a r _ s e a r c h (a , n , key ) ;

if ( pos == -1)
printf ( " Element not found \ n " ) ;
else
printf ( " Element found at position % d \ n " , pos +1) ;

return 0;
}
