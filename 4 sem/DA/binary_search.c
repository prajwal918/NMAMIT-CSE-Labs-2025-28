#include <stdio.h>
int binary_search ( int a [], int n, int key )
{
    int low = 0, high = n - 1, mid ;
    while ( low <= high )
    {
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

int main ()
{
    int a [100], n, i, key, pos ;
    printf ("Enterthenumberofelements:" ) ;
    scanf ("%d", & n ) ;
    printf ("Entertheelements(insortedorder):" ) ;
    for ( i = 0; i < n ; i ++)
        scanf ("%d", & a [ i ]) ;

    printf ("Enterthekeyelementtosearch:" ) ;
    scanf ("%d", & key ) ;

    pos = binary_search (a, n, key ) ;

    if ( pos == -1)
        printf ("Elementnotfound\n" ) ;
    else
        printf ("Elementfoundatposition%d\n", pos + 1) ;

    return 0;
}
