#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph [ MAX ] [ MAX ] ;
int indegree [ MAX ], n ;

void topological_sort ( )
{
    int visited [ MAX ] = { 0 } ;
    int count = 0 ;

    while ( count < n )
    {
        int found = 0 ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            if ( indegree [ i ] == 0 && ! visited [ i ] )
            {
                printf ("%d\t", i ) ;
                visited [ i ] = 1 ;
                found = 1 ;
                count ++ ;

                for ( int j = 0 ; j < n ; j ++ )
                {
                    if ( graph [ i ] [ j ] == 1 )
                        indegree [ j ] -- ;
                }
            }
        }

        if ( ! found )
        {
            printf ("Cycle detected! Topological Sort not possible"
                   ) ;
            return ;
        }
    }
}

int main ( )
{
    printf ("Enter number of vertices: " ) ;
    scanf ("%d", & n ) ;

    printf ("Enter adjacency matrix:\n" ) ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            scanf ("%d", & graph [ i ] [ j ] ) ;
            if ( graph [ i ] [ j ] == 1 )
                indegree [ j ] ++ ;
        }
    }

    printf ("Topological Order:\n" ) ;
    topological_sort ( ) ;

    return 0 ;
}
