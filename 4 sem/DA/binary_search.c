# include < stdio .h >
int b i n a r y _ s e a r c h ( int a [] , int n , int key ) {
int low = 0 , high = n -1 , mid ;
while ( low <= high ) {
mid = ( low + high ) / 2;
if ( a [ mid ] == key )
return mid ;
else if ( a [ mid ] < key )
low = mid + 1;
else
high = mid - 1;
}
return -1;
}

int main () {
int a [100] , n , i , key , pos ;
printf ( " Enter the number of elements : " ) ;
scanf ( " % d " , & n ) ;
printf ( " Enter the elements ( in sorted order ) : " ) ;
for ( i =0; i < n ; i ++)
scanf ( " % d " , & a [ i ]) ;

printf ( " Enter the key element to search : " ) ;
scanf ( " % d " , & key ) ;

pos = b i n a r y _ s e a r c h (a , n , key ) ;

if ( pos == -1)
printf ( " Element not found \ n " ) ;
else
printf ( " Element found at position % d \ n " , pos +1) ;

return 0;
}
