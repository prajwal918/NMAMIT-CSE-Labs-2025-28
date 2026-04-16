#include <stdio.h>
#include <stdlib.h>

int a [ 100 ] ;

void read ( int n )
{
for ( int i = 0 ; i < n ; i ++ )
scanf ("%d" , & a [ i ] ) ;
}

void display ( int n )
{
for ( int i = 0 ; i < n ; i ++ )
printf ("%d\t" , a [ i ] ) ;
}

void insertion_sort ( int n )
{
int key , j ;
for ( int i = 1 ; i < n ; i ++ )
{
key = a [ i ] ;
j = i - 1 ;
while ( j >= 0 && a [ j ] > key )
{
a [ j + 1 ] = a [ j ] ;
j -- ;
}
a [ j + 1 ] = key ;
}
}

int main ( )
{
int n ;
printf ("Enter the number of elements: " ) ;
scanf ("%d" , & n ) ;

printf ("Enter the elements: " ) ;
read ( n ) ;

printf ("\nElements are: " ) ;
display ( n ) ;

insertion_sort ( n ) ;

printf ("\nSorted array: " ) ;
display ( n ) ;

return 0 ;
}
