#include <stdio.h>
void selection_sort ( int a [], int n )
{
    int i, j, min, temp ;
    for ( i = 0; i < n - 1; i ++)
    {
        min = i ;
        for ( j = i + 1; j < n ; j ++)
        {
            if ( a [ j ] < a [ min ])
                min = j ;
        }
        temp = a [ i ];
        a [ i ] = a [ min ];
        a [ min ] = temp ;
    }
}

int main ()
{
    int a [100], n, i ;
    printf ("Enterthenumberofelements:" ) ;
    scanf ("%d", & n ) ;
    printf ("Entertheelements:" ) ;
    for ( i = 0; i < n ; i ++)
        scanf ("%d", & a [ i ]) ;

    selection_sort (a, n ) ;

    printf ("\nSortedarray:" ) ;
    for ( i = 0; i < n ; i ++)
        printf ("%d\t", a [ i ]) ;
    printf ("\n" ) ;
    return 0;
}
