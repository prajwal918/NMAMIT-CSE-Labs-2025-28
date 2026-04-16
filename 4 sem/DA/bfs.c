#include <stdio.h>

void read_mat ( int a [ 10 ] [ 10 ] , int n )
{
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
scanf ("%d" , & a [ i ] [ j ] ) ;
}
}
}

void display_mat ( int a [ 10 ] [ 10 ] , int n )
{
for ( int i = 0 ; i < n ; i ++ )
{
for ( int j = 0 ; j < n ; j ++ )
{
printf ("%d\t" , a [ i ] [ j ] ) ;
}
printf ("\n" ) ;
}
}

void bfs ( int adj_mat [ 10 ] [ 10 ] , int queue [ ] , int visited [ ] , int
start , int n )
{
int front = 0 , rear = 0 ;
queue [ rear ++ ] = start ;
visited [ start ] = 1 ;

while ( front <= rear )
{
int current = queue [ front ++ ] ;
printf ("Visiting %d Vertex\n" , current ) ;

for ( int i = 0 ; i < n ; i ++ )
{
if ( adj_mat [ current ] [ i ] == 1 && visited [ i ] == 0 )
{
queue [ ++ rear ] = i ;
visited [ i ] = 1 ;
}
}
}
}

int main ( )
{
int n , s ;
printf ("Enter the number of vertices:\n" ) ;
scanf ("%d" , & n ) ;

int adj_mat [ 10 ] [ 10 ] , visited [ n ] , queue [ n ] ;

for ( int i = 0 ; i < n ; i ++ )
visited [ i ] = 0 ;

printf ("Enter the adjacency matrix:\n" ) ;
read_mat ( adj_mat , n ) ;

printf ("The adjacency matrix is:\n" ) ;
display_mat ( adj_mat , n ) ;

printf ("Enter the starting vertex:\n" ) ;
scanf ("%d" , & s ) ;

bfs ( adj_mat , queue , visited , s , n ) ;

return 0 ;
}
