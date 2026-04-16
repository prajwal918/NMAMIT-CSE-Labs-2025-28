# include < stdio .h >
void s e l e c t i o n _ s o r t ( int a [] , int n ) {
int i , j , min , temp ;
for ( i =0; i <n -1; i ++) {
min = i ;
for ( j = i +1; j < n ; j ++) {
if ( a [ j ] < a [ min ])
min = j ;
}
temp = a [ i ];
a [ i ] = a [ min ];
a [ min ] = temp ;
}
}

int main () {
int a [100] , n , i ;
printf ( " Enter the number of elements : " ) ;
scanf ( " % d " , & n ) ;
printf ( " Enter the elements : " ) ;
for ( i =0; i < n ; i ++)
scanf ( " % d " , & a [ i ]) ;

s e l e c t i o n _ s o r t (a , n ) ;

printf ( " \ nSorted array : " ) ;
for ( i =0; i < n ; i ++)
printf ( " % d \ t " , a [ i ]) ;
printf ( " \ n " ) ;
return 0;
}
