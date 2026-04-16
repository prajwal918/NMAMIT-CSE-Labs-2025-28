#include <stdio.h>

#define MAX 10
#define INF 99999

int n ;

void floyd ( int dist [ MAX ] [ MAX ] )
{
int i , j , k ;

for ( k = 0 ; k < n ; k ++ )
{
for ( i = 0 ; i < n ; i ++ )
{
for ( j = 0 ; j < n ; j ++ )
{
// Ifpaththroughkisshorter , updatedist [ i ] [ j ]
if ( dist [ i ] [ k ] + dist [ k ] [ j ] < dist [ i ] [ j ] )
dist [ i ] [ j ] = dist [ i ] [ k ] + dist [ k ] [ j ] ;
}
}
}
}

void printMatrix ( int dist [ MAX ] [ MAX ] )
{
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
if ( dist [ i ] [ j ] == INF )
printf ("INF " ) ;
else
printf ("%d " , dist [ i ] [ j ] ) ;
}
printf ("\n" ) ;
}
}

int main ( )
{
int dist [ MAX ] [ MAX ] ;

printf ("Enter the number of vertices: " ) ;
scanf ("%d" , & n ) ;

printf ("Enter the distance matrix (use 99999 for INF):\n" ) ;
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
scanf ("%d" , & dist [ i ] [ j ] ) ;
}
}

printf ("Original Distance Matrix:\n" ) ;
printMatrix ( dist ) ;

floyd ( dist ) ;

printf ("\nShortest Path Matrix:\n" ) ;
printMatrix ( dist ) ;

return 0 ;
}
