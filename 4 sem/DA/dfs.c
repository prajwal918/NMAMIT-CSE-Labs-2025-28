#include <stdio.h>

void read_mat ( int a [ 10 ] [ 10 ], int n )
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            scanf ("%d", & a [ i ] [ j ] ) ;
        }
    }
}

void display_mat ( int a [ 10 ] [ 10 ], int n )
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            printf ("%d\t", a [ i ] [ j ] ) ;
        }
        printf ("\n" ) ;
    }
}

void dfs ( int adj_mat [ 10 ] [ 10 ], int visited [ ], int visiting, int n )
{
    printf ("Visiting %d Vertex\n", visiting ) ;
    visited [ visiting ] = 1 ;

    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( adj_mat [ visiting ] [ i ] == 1 && visited [ i ] == 0 )
        {
            dfs ( adj_mat, visited, i, n ) ;
        }
    }
}

int main ( )
{
    int n, s ;
    printf ("Enter the number of vertices:\n" ) ;
    scanf ("%d", & n ) ;

    int adj_mat [ 10 ] [ 10 ], visited [ n ] ;

    for ( int i = 0 ; i < n ; i ++ )
        visited [ i ] = 0 ;

    printf ("Enter the adjacency matrix:\n" ) ;
    read_mat ( adj_mat, n ) ;

    printf ("The adjacency matrix is:\n" ) ;
    display_mat ( adj_mat, n ) ;

    printf ("Enter the starting vertex:\n" ) ;
    scanf ("%d", & s ) ;

    dfs ( adj_mat, visited, s, n ) ;

    return 0 ;
}
