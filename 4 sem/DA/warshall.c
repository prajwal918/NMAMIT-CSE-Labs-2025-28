#include <stdio.h>

#define MAX 10

int n ;

void warshall ( int graph [ MAX ] [ MAX ] )
{
int i , j , k ;

for ( k = 0 ; k < n ; k ++ )
{
for ( i = 0 ; i < n ; i ++ )
{
for ( j = 0 ; j < n ; j ++ )
{
// Ifvertexkisonapathfromitoj ,
// updategraph [ i ] [ j ] usinglogicalOR
graph [ i ] [ j ] = graph [ i ] [ j ] || ( graph [ i ] [ k ] && graph
[ k ] [ j ] ) ;
}
}
}
}

void printMatrix ( int graph [ MAX ] [ MAX ] )
{
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
printf ("%d " , graph [ i ] [ j ] ) ;
}
printf ("\n" ) ;
}
}

int main ( )
{
int graph [ MAX ] [ MAX ] ;

printf ("Enter the number of vertices: " ) ;
scanf ("%d" , & n ) ;

printf ("Enter the adjacency matrix:\n" ) ;
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
scanf ("%d" , & graph [ i ] [ j ] ) ;
}
}

printf ("Original Adjacency Matrix:\n" ) ;
printMatrix ( graph ) ;

warshall ( graph ) ;

printf ("\nTransitive Closure:\n" ) ;
printMatrix ( graph ) ;

return 0 ;
}
